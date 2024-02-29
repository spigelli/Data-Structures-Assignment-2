# Make file for compiling just main.cpp to the target executable

# Variables
CC = g++
CFLAGS = -Wall -Wextra -std=c++11 -g
TARGET = main
SOURCES = main.cpp

# Target: main
# This target will compile the main.cpp file to the target executable.
main: $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Target: clean
# This target will remove the target executable.
clean:
	rm -f $(TARGET)
	rm -rf $(TARGET).dSYM
