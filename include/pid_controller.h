#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

// Define a PID control structure
typedef struct {
    float kp;
    float ki;
    float kd;
    float previous_error;
    float integral;
    float control_signal;
} PID;

int pid_control(PID* pid, int sensor_value, int setpoint);

#endif // PID_CONTROLLER_H
