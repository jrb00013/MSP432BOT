CC = gcc
CFLAGS = -Wall -O2 -g

# Target MCU
MCU = msp432

# File names
SRC = main.c motor_control.c sensors.c pid_controller.c uart.c
OBJ = $(SRC:.c=.o)
EXEC = robot

# Compiler options
LDFLAGS = -lm

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
