#include "msp.h"
#include "motor_control.h"
#include "sensors.h"
#include "pid_controller.h"
#include "uart.h"

#define MOTOR_SPEED 500
#define TURN_ANGLE  90

int main(void) {
    // Initialize the MSP432
    WDT_A_hold(WDT_A_BASE);  // Disable watchdog timer
    init_uart();              // Initialize UART communication
    init_motors();            // Initialize motors
    init_sensors();           // Initialize sensors

    // Main loop
    while (1) {
        int sensor_data = read_sensors();
        int control_signal = pid_control(sensor_data);

        // Adjust motors based on PID control signal
        set_motor_speed(MOTOR_SPEED + control_signal);
        
        // Example of turning the robot if a condition is met
        if (sensor_data > SOME_THRESHOLD) {
            turn_robot(TURN_ANGLE);  // Turn robot if condition met
        }
        
        __delay_cycles(1000000);  // Delay for a bit before next loop
    }
}
