# MSP432 Microcontroller Robot 🤖

Control a robot using the MSP432 microcontroller with C programming.

## File Overview
- **main.c**: Entry point for the application.
- **motor_control.c**: Functions to configure and control the motors.
- **pid_controller.c**: PID control logic for motor speed and direction.
- **sensors.c**: Functions to read data from sensors.
- **uart.c**: UART communication for data transmission.
- **msp.h**: Header file containing MSP432 register definitions.
- **Makefile**: Build automation file.

## How to Compile and Run:
1. Compile using the provided `Makefile`.
2. Load the program onto the MSP432 with your IDE (I used CCS from TI)
3. Power and run the robot on a specified track. 

## Requirements:
- MSP432 Microcontroller
- C Compiler
