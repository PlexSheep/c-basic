.PHONY = all pre testfiles bigfiles
SOURCES = $(wildcard *.c)
BINARIES = $(SOURCES:%.c=%)
EXECUTABLES= $(addprefix bin/,${BINARIES})
all: pre $(EXECUTABLES) huffman/bin/huffman testfiles

big: all bigfiles
pre:
		@mkdir -p bin huffman/bin huffman/testfiles

clean:
		rm -rvf bin huffman/testfiles huffman/bin

huffman/bin/huffman: huffman/huffman.c
		$(CC) $(CFLAGS) -o $@ $< -lm

testfiles:
		@dd if=/dev/urandom of=huffman/testfiles/1K-random.img count=1KiB
		@dd if=/dev/urandom of=huffman/testfiles/10K-random.img count=10KiB
		@dd if=/dev/urandom of=huffman/testfiles/100K-random.img count=100KiB
		@dd if=/dev/urandom of=huffman/testfiles/1M-random.img count=1MiB
		@dd if=/dev/urandom of=huffman/testfiles/10M-random.img count=10MiB
		@dd if=/dev/zero of=huffman/testfiles/1K-zero.img count=1KiB
		@dd if=/dev/zero of=huffman/testfiles/10K-zero.img count=10KiB
		@dd if=/dev/zero of=huffman/testfiles/100K-zero.img count=100KiB
		@dd if=/dev/zero of=huffman/testfiles/1M-zero.img count=1MiB
		@dd if=/dev/zero of=huffman/testfiles/10M-zero.img count=10MiB
		@echo -e "Wer\ndas\nliest\nist\ndoof\n" > huffman/testfiles/tiny.txt
		@yes 'SAFJALJ AF OIAIFOsdp' | head -c 100KB > huffman/testfiles/small.txt
		@yes 'lslfkpoipop iipfiasp' | head -c 1MB > huffman/testfiles/mid.txt
		

bigfiles:
		@echo "Building some bigger testfiles, this might take a while and draw some performance"
		@dd if=/dev/urandom of=huffman/testfiles/100M-random.img count=100MiB
		@dd if=/dev/zero of=huffman/testfiles/100M-zero.img count=100MiB
		@dd if=/dev/urandom of=huffman/testfiles/1G-random.img count=1GiB
		@dd if=/dev/urandom of=huffman/testfiles/10G-random.img count=10GiB
		@dd if=/dev/zero of=huffman/testfiles/1G-zero.img count=1GiB
		@dd if=/dev/zero of=huffman/testfiles/10G-zero.img count=10GiB
		@yes 'a sla d JK J Kkl' | head -c 100MB > huffman/testfiles/big.txt
		@yes ' POP OPO )()( as' | head -c 1G > huffman/testfiles/huge.txt

$(EXECUTABLES): $(SOURCES)
		$(CC) $(CFLAGS) -o $@ $< -lm
