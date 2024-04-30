CC = g++
CFLAGS = -std=c++11 -Wall
TARGET_DIR = bin

.PHONY: all clean

all: build

build:
	@echo "Creating executable file"
	@mkdir $(TARGET_DIR)
	$(CC) $(CFLAGS) main.cpp -o $(TARGET_DIR)/out

clean:
	@rm -rf $(TARGET_DIR)/out
