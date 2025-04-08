#include "msp.h"
#include "sensors.h"

// Initialize sensor pins and peripherals
void init_sensors(void) {
    // Configure Ultrasonic Sensor
    // Assuming the ultrasonic sensor trigger is connected to P2.1 and echo to P2.2
    P2DIR |= BIT1;    // Set P2.1 as output (Trigger)
    P2DIR &= ~BIT2;   // Set P2.2 as input (Echo)
    
    // Configure Infrared Sensor
    // Assuming infrared sensor output is connected to P1.0
    P1DIR &= ~BIT0;   // Set P1.0 as input (IR sensor)
    
    // Configure Temperature Sensor
    // Assuming ADC is used for temperature sensor, connected to P1.1
    P1DIR &= ~BIT1;   // Set P1.1 as input (Temperature sensor)
    init_adc();       // Initialize ADC for reading temperature sensor

    // Additional sensor initialization can go here...
}

// Read ultrasonic sensor (returns distance in cm)
int read_ultrasonic_sensor(void) {
    // Send a pulse to trigger the ultrasonic sensor
    P2OUT |= BIT1;  // Send trigger pulse
    __delay_cycles(10);  // Wait for pulse duration
    P2OUT &= ~BIT1;  // Stop the pulse

    // Measure the time for echo to return
    int echo_time = 0;
    while (!(P2IN & BIT2));  // Wait for the rising edge (echo start)
    while (P2IN & BIT2) {    // Wait for the falling edge (echo end)
        echo_time++;  // Count cycles of the echo pulse
    }

    // Convert time to distance (simplified calculation)
    int distance = echo_time / 58;  // Assuming 58 µs/cm for sound speed

    return distance;
}

// Read infrared sensor (binary signal: 0 = no object detected, 1 = object detected)
int read_infrared_sensor(void) {
    return (P1IN & BIT0) ? 1 : 0;  // Read the input from infrared sensor pin
}

// Read temperature sensor via ADC (assuming a simple analog sensor)
int read_temperature_sensor(void) {
    // Start ADC conversion on P1.1
    ADC14->CTL0 |= ADC14_CTL0_SC;  // Start conversion
    while (ADC14->CTL0 & ADC14_CTL0_SC);  // Wait for conversion to complete

    // Get the result from the ADC
    int temperature = ADC14->MEM[0];  // Read the temperature value from ADC
    return temperature;
}

// Initialize ADC for the temperature sensor
void init_adc(void) {
    // Configure ADC pins (P1.1 for temperature sensor)
    P1SEL0 |= BIT1;  // Set P1.1 to ADC function

    // Configure ADC settings
    ADC14->CTL0 = ADC14_CTL0_SHT0_2 | ADC14_CTL0_ON | ADC14_CTL0_MSTR;  // Set ADC parameters
    ADC14->CTL1 = ADC14_CTL1_RES_2;  // Set resolution (14-bit)
    ADC14->CTL0 |= ADC14_CTL0_ENC;  // Enable ADC conversion
}
