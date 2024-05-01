CC = g++
CFLAGS = -std=c++17

.PHONY: all clean

all: build

build:
	@echo "Creating executable file"
	$(CC) $(CFLAGS) main.cpp -o out

clean:
	@rm out
