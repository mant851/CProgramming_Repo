# List of all C programs to compile
PROGS := exercise_4_2.c exercise_4_3.c exercise_4_4.c exercise_4_5.c \
         exercise_4_7.c exercise_4_8.c exercise_4_9.c exercise_4_10.c \

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
