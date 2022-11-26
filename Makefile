# see https://opensource.com/article/18/8/what-how-makefile
# Usage:
# make        # compile all binary
# make clean  # remove ALL binaries and objects

.PHONY = all clean

SRCS := $(wildcard *.c)
BINS := $(SRCS:%.c=%)

all: ${BINS}

%: %.o
		@echo "Linking..."
		gcc $< -o bin/$@ -lm

%.o: %.c
		echo "Creating object..."
		gcc -c $< -o obj/

clean:
		@echo "Cleaning up..."
		rm -rvf *.o ${BINS}
