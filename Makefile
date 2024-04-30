CC = g++
CFLAGS = -std=c++11 -Wall

.PHONY: all clean

all: build

build:
	@echo "Creating executable file"
	$(CC) $(CFLAGS) main.cpp -o out

clean:
	@rm out
