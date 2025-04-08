#include "msp.h"
#include "motor_control.h"
#include "sensors.h"
#include "pid_controller.h"
#include "uart.h"

// Constants
#define MOTOR_SPEED 500
#define TURN_ANGLE 90
#define SENSOR_THRESHOLD 50
#define MAX_SENSOR_VALUE 1023

// Global PID variables
static PID pid_left = {1.0, 0.5, 0.1, 0, 0, 0};  // PID for left motor
static PID pid_right = {1.0, 0.5, 0.1, 0, 0, 0}; // PID for right motor

// Function prototypes
void init_system(void);
void main_loop(void);

int main(void) {
    // Initialize system components
    init_system();

    // Main control loop
    while (1) {
        main_loop();
    }

    return 0;
}

void init_system(void) {
    WDT_A_hold(WDT_A_BASE);  // Disable watchdog timer
    init_uart();              // Initialize UART communication
    init_motors();            // Initialize motors
    init_sensors();           // Initialize sensors
}

void main_loop(void) {
    int sensor_data = read_sensors();
    
    // Apply PID control to motor speeds based on sensor data
    int left_motor_speed = pid_control(&pid_left, sensor_data, 0);
    int right_motor_speed = pid_control(&pid_right, sensor_data, 0);

    // Adjust motors based on PID output
    set_motor_speed(left_motor_speed, right_motor_speed);

    // Example of turning the robot if a threshold condition is met
    if (sensor_data > SENSOR_THRESHOLD) {
        turn_robot(TURN_ANGLE);  // Turn robot if condition met
    }

    __delay_cycles(1000000);  // Delay for a bit before next loop
}
