# compiler name: gcc for C program, define as g++ for C++
CC = gcc

# compiler flags
# -g    adds debugging information to the executable file
# 			(e.g. TARGET.dSYM directory)
# -Wall turns on most, but not all, compiler warnings
CFLAGS = -Wall

# build target executable
TARGET = vsub

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
