#SOURCES = $(wildcard *.c)
#BINARIES = $(SOURCES:%.c=%)
#CFLAGS = -g
#CC = gcc
#
#all: pre $(BINARIES)
#
#pre:
#		@mkdir -p bin huffman/bin huffman/testfiles
#
SOURCES = $(wildcard *.c)
BINARIES = $(SOURCES:%.c=%)
EXECUTABLES= $(addprefix bin/,${BINARIES})
all: pre $(EXECUTABLES)

pre:
		@mkdir -p bin

$(EXECUTABLES): $(SOURCES)
		$(CC) $(CFLAGS) -o $@ $< -lm
