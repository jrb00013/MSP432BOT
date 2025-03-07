#include "msp.h"

// Function prototypes
void init_motors(void);
void set_motor_speed(int speed);
void turn_robot(int angle);

void main(void) {
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;  // Stop watchdog timer

    init_motors(); // Initialize motor control

    set_motor_speed(1000); // Example speed value
    turn_robot(90);        // Turn 90 degrees

    while (1);
}

// Function to initialize motor pins and PWM
void init_motors(void) {
    // Configure PWM pins (Assuming P2.4 for left motor, P2.5 for right motor)
    P2DIR |= BIT4 | BIT5;    // Set P2.4 & P2.5 as outputs
    P2SEL0 |= BIT4 | BIT5;   // Set primary function (PWM mode)
    P2SEL1 &= ~(BIT4 | BIT5);

    // Configure Timer_A0 for PWM (Assume 3kHz PWM)
    TA0CCR0 = 3000 - 1;  // Set PWM period (Timer_A0 Capture/Compare 0)
    
    // Configure CCR1 for Motor 1 (P2.4)
    TA0CCTL1 = 0x00E0;  // OUTMOD_7 (Reset/Set)
    TA0CCR1 = 0;        // Start with 0% duty cycle
    
    // Configure CCR2 for Motor 2 (P2.5)
    TA0CCTL2 = 0x00E0;  // OUTMOD_7 (Reset/Set)
    TA0CCR2 = 0;        // Start with 0% duty cycle

    // Start Timer_A in up mode, sourced by SMCLK
    TA0CTL = 0x0210;  // TASSEL_2 (SMCLK) | MC_1 (Up mode)
}

// Function to set motor speed (adjust PWM duty cycle)
void set_motor_speed(int speed) {
    if (speed > 3000) speed = 3000; // Limit speed to max PWM
    if (speed < 0) speed = 0;       // Prevent negative values

    TA0CCR1 = speed;  // Set duty cycle for Motor 1 (P2.4)
    TA0CCR2 = speed;  // Set duty cycle for Motor 2 (P2.5)
}

// Function to turn the robot (differential motor control)
void turn_robot(int angle) {
    if (angle > 0) {  // Turn Right
        TA0CCR1 = 1500; // Reduce speed for left motor
        TA0CCR2 = 3000; // Full speed for right motor
    } else {  // Turn Left
        TA0CCR1 = 3000; // Full speed for left motor
        TA0CCR2 = 1500; // Reduce speed for right motor
    }
}
