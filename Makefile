CC = g++
CFLAGS = -std=c++20 -Wall -Wextra

all:
	@echo "Creation of the executable file"
	$(CC) $(CFLAGS) -o out test.cpp

clean:
	rm out