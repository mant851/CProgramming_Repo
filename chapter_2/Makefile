# List of all C programs to compile
PROGS := exercise_2_1.c exercise_2_2.c exercise_2_3.c exercise_2_4.c exercise_2_5.c \
         exercise_2_6.c exercise_2_7.c exercise_2_8.c exercise_2_9.c exercise_2_10.c \

# Compiler to use
CC := gcc

# Flags for the compiler
CFLAGS := -Wall -std=c99 -g 

# Default target: compile all programs
all: $(PROGS:.c=)

# Rule to compile each program
exercise_%: exercise_%.c
	$(CC) $(CFLAGS) $< -o $@ -lm

# Target to run a specific program
run_%: exercise_%
	./$*

# Target to clean up compiled files
clean:
	rm -f $(PROGS:.c=)

# Phony targets (targets that don't correspond to actual files)
.PHONY: all clean
