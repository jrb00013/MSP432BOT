CC = msp430-gcc
CFLAGS = -Wall -g -I./include
SRC_DIR = src
BUILD_DIR = build

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)
TARGET = $(BUILD_DIR)/MSP432BOT.elf

all: $(TARGET)

$(TARGET): $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o $(TARGET)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
