#include "msp.h"

static float kp = 1.0;  // Proportional gain
static float ki = 0.5;  // Integral gain
static float kd = 0.1;  // Derivative gain

static float previous_error = 0;
static float integral = 0;


int pid_control(PID* pid, int sensor_value, int setpoint) {
    // Error calculation
    int error = setpoint - sensor_value;
    pid->integral += error;
    
    // Anti-windup: Prevent integral term from growing too large
    if (pid->integral > 1000) pid->integral = 1000;
    if (pid->integral < -1000) pid->integral = -1000;

    int derivative = error - pid->previous_error;

    // Compute control signal
    int control_signal = (pid->kp * error) + (pid->ki * pid->integral) + (pid->kd * derivative);
    
    // Save error for the next iteration
    pid->previous_error = error;
    
    return control_signal;
}
