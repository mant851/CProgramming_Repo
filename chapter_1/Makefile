# List of all C programs to compile (Exercise_1_1.c to Exercise_1_13.c)
PROGS := exercise_1_1.c exercise_1.2.c exercise_1.3.c exercise_1.4.c exercise_1.5.c \
         exercise_1.6.c exercise_1.7.c exercise_1.8.c exercise_1.9.c exercise_1.10.c \
         exercise_1.12.c exercise_1.13.c exercise_1.14.c exercise_1.15.c 
# Compiler to use
CC := gcc
 
# Flags for the compiler
CFLAGS := -Wall -std=c99
 
# Default target: compile all programs
all: $(PROGS:.c=)
 
# Rule to compile each program
Exercise_%: Exercise_%.c
	$(CC) $(CFLAGS) $< -o $@
 
# Target to run a specific program
run_%: Exercise_%
	./$*
 
# Target to clean up compiled files
clean:
	rm -f $(PROGS:.c=)
 
# Phony targets (targets that don't correspond to actual files)
.PHONY: all clean
