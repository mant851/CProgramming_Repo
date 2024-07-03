# List of all C programs to compile
PROGS := exercise_1_1.c exercise_1_2.c exercise_1_3.c exercise_1_4.c exercise_1_5.c \
         exercise_1_6.c exercise_1_7.c exercise_1_8.c exercise_1_9.c exercise_1_10.c \
         exercise_1_12.c exercise_1_13.c exercise_1_14.c exercise_1_15.c

# Compiler to use
CC := gcc

# Flags for the compiler
CFLAGS := -Wall -std=c99 -g

# Default target: compile all programs
all: $(PROGS:.c=)

# Rule to compile each program
exercise_%: exercise_%.c
	$(CC) $(CFLAGS) $< -o $@

# Target to run a specific program
run_%: exercise_%
	./$*

# Target to clean up compiled files
clean:
	rm -f $(PROGS:.c=)

# Phony targets (targets that don't correspond to actual files)
.PHONY: all clean
