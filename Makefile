# Compiler
CC = gcc

# Compiler flags (include directory)
CFLAGS = -I.


all: Evaluation

# Here we link object files to create the executable
Evaluation: Task1.o
	$(CC) -o MakeFileTask5_1 Task1.o

# Here we compile main.c to main.o
main.o: main.c
	$(CC) $(CFLAGS) -c Task1.c

# Clean up: It removes the object files
clean:
	rm -f Evaluation Task1.o
