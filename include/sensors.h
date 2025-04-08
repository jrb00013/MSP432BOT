#ifndef SENSORS_H
#define SENSORS_H

// Function prototypes for sensor initialization and reading
void init_sensors(void);
int read_ultrasonic_sensor(void);
int read_infrared_sensor(void);
int read_temperature_sensor(void);

#endif // SENSORS_H
