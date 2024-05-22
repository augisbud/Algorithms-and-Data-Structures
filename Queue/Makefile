SRC_DIR=src
BUILD_DIR=build
TARGET=queue-example

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean

all: $(BUILD_DIR) $(TARGET)

$(BUILD_DIR):
	mkdir $(BUILD_DIR)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	gcc -Wall -std=c99 -c $< -o $@

$(TARGET): $(OBJS)
	gcc -Wall -std=c99 $^ -o $@

clean:
	del /Q $(BUILD_DIR)\* $(TARGET).exe
	rmdir $(BUILD_DIR)