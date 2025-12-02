target=$(BUILD_DIR)/hello
cc=gcc
cflags=-Wall -g
SRC_DIR=src
BUILD_DIR=build
SRC=$(wildcard $(SRC_DIR)/*.c)
OBJ=$(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRC))

all: $(target)

$(target): $(OBJ)
	$(cc) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c|$(BUILD_DIR)
	$(cc) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)
