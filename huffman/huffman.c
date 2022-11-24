#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

off_t fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
	return st.st_size;

    fprintf(stderr, "Cannot determine size of %s: %s\n", filename,
	    strerror(errno));

    return -1;
}

void helper() {
    printf("huffman compression algorithm implementation for educational "
	    "purposes.\n\nSyntax:\nhuffman -f fileToCompress\t\tcompress the "
	    "given file\nhuffman -xf fileToDecompress\t\tdecompress the given "
	    "file\nhuffman -h\t\t\t\tshow this help\nhuffman -v\t\t\t\tverbose\n");
}

int main(int argc, char *argv[]) {
    int opt;
    bool extract_mode = false;
    bool verbose = false;
    bool debug = false;
    char *filestring = NULL;
    uint64_t filelen;

    FILE *fptrR = NULL; 	// file pointer for reading
    FILE *fptrW = NULL; 	// file pointer for writing

    while ((opt = getopt(argc, argv, "dvxhf:")) != -1) {
	if (debug)
	    printf("optarg is: %s\n", optarg);
	switch (opt) {
	    case 'v':
		verbose = true;
		break;
	    case 'd':
		debug = true;
		break;
	    case 'f':
		filestring = optarg;
		break;
	    case 'h':
		helper();
		exit(0);
		break;
	    case 'x':
		extract_mode = true;
		break;
	    default:
		fprintf(stderr, "Usage: %s [-dvhx -f] [file]\n", argv[0]);
		exit(EXIT_FAILURE);
	}
    }

    // Now optind (declared extern int by <unistd.h>) is the index of the first
    // non-option argument. If it is >= argc, there were no non-option arguments.

    if (verbose)
	printf("selected file: %s\n", filestring);

    if (filestring) {
	if(debug)
	    printf("[DEBUG]processing given file argument.\n");
	// open the given file in binary mode, I want this to work with any files,
	// not just textfiles.
	fptrR = fopen(filestring, "rb");
	if (fptrR == NULL) {
	    fprintf(stderr, "The given file does not exist or is unavailable.\n");
	    exit(EXIT_FAILURE);
	}
	// causes bugs.
	fseek(fptrR, 0L, SEEK_END);
	filelen = ftell(fptrR);
	fseek(fptrR, 0L, SEEK_SET);
    } 
    else {
	// empty filestring or filestring is NULL
	fprintf(stderr, "Usage: %s [-dvhx -f] [file]\n", argv[0]);
	exit(EXIT_FAILURE);
    }

    // TODO check file size and spit a "what the heck im not a 10x dev, do a
    if(verbose)
	printf("filesize: %ldB\n", filelen);

    if (extract_mode) {
	printf("extracting is not yet implemented.\n");
	// decompress the file
    }

    else {
	// compress the file
	if (verbose)
	    printf("compressing file...\n");

	// frequency analysis

	uint8_t buf[512];

	// dump start of file if debugging
	// FIXME add conditions if the part to print is smaller than 512B
	if(debug){
	    printf("[DEBUG]First 512 bytes are:\n");
	    fread(buf, 1, 512, fptrR);
	    for(int i=0;i<512;i++){
		if(i%16==0)
		    printf("%08x\t", i);
		printf("%02x ", buf[i]);
		if(i%16==7)
		    printf(" ");
		if(i%16==15){
		    printf("\n");
		}
	    }
	}

	uint64_t occurences[256];
	for(int i=0;i<256;i++){
	    occurences[i]=0;    
	}
	// FIXME doesnt loop through full file! only 50% for larger files
	// Backup occurence counting algorithm
	/*
	   while(!feof(fptrR)){
	   fseek(fptrR, 512, SEEK_CUR);
	   if(fread(buf, 1, 512, fptrR)){
	   for(int i=0;i<512;i++){
	   occurences[buf[i]]++;
	   }
	   }
	   else{
	   fprintf(stderr, "Error when processing file.\n");
	   exit(EXIT_FAILURE);
	   }

	// advance filepointer 512 bytes foreward. If not possible, set endOfFile flag.
	// FIXME
	offset += 512;
	}
	*/
	// backup
	/*
	   while(1){
	   fseek(fptrR, 512, SEEK_CUR);	// this line seems the be making the most problems

	//	On  success, fread() and fwri)te() return the number of items read or written.  
	//	This number equals the number of bytes transferred only when size is
	//	1.  If an error occurs, or the end of the file is reached, the return value is a short item count (or zero).
	//	fread() does not distinguish between end-of-file and error, and callers must use feof(3) and ferror(3) to determine which occurred.

	// FIXME )This is a buggy mess
	if(512 == fread(buf, 1, 512, fptrR)){
	for(int i=0;i<512;i++){
	occurences[buf[i]]++;)
	}
	})
	else if(0 == fread(buf, 1, 512, fptrR)){
	if(debug)
	printf("[DEBUG]fread returned 0! ftell for current position is %lu\n", ftell(fptrR));
	break;
	}
	else{
	fprintf(stderr, "Error when processing file: %lu, At offset %lu\n",fread(buf, 1, 512, fptrR), ftell(fptrR));
	exit(EXIT_FAILURE);
	}
	if(ftell(fptrR) > filelen) {
	// ??? unknown error
	fprintf(stderr, "tried reading further than the file is long somehow?\n");
	exit(EXIT_FAILURE);
	}
	}
	*/
	// ALMOST WORKS! ~200 bytes lost for a 10M file!!!
	uint8_t bufMini[1];
	while(1){
	    if(fread(bufMini, 1, 1, fptrR)){
		occurences[buf[0]]++;	
	    }
	    else{
		if(ferror(fptrR)){
		    fprintf(stderr, "encountered error when reading file.\n");
		    exit(EXIT_FAILURE);
		}
	    }
	    fseek(fptrR, 1, SEEK_SET);
		if(ferror(fptrR)){
		    fprintf(stderr, "encountered error when reading file.\n");
		    exit(EXIT_FAILURE);
		}
		else if(feof(fptrR)){
		    continue;
		}
	}
	if(debug){
	    printf("Occurences (Hex):\n");
	    for(int i=0;i<256;i++){
		if(i%4==0)
		    printf("\n");
		printf("0x%02x: %016lx\t", i, occurences[i]);
	    }
	    printf("\n\nfile length(by pointer):\t\t%luB\n", filelen);
	    long long int addedUpOccurences = 0; // FIXME might not be enough storage for larger files!
	    for(int i=0;i<256;i++){
		addedUpOccurences += occurences[i];
	    }
	    printf("file length(added up occurences):\t%lldB\n", addedUpOccurences);
	}

	if(verbose)
	    printf("\n\nDone calculating occurences of bytes.\n");

	// TODO
	// calculate the frequencies of the bytes.
	double frequencies[256];
	for(int i=0;i<256;i++){
	    frequencies[i]=((double)occurences[i]/(double)filelen)*100;	// calculate frequencies of bytes in percent (example: 05.23 (%))
	}
	if(debug){
	    printf("Frequencies:\n");
	    for(int i=0;i<256;i++){
		if(i%8==0)
		    printf("\n");
		printf("0x%02x: %05.02f%%\t", i, frequencies[i]);
	    }
	    double addedUpFrequencies = 0; 
	    for(int i=0;i<256;i++){
		addedUpFrequencies += frequencies[i];
	    }
	    printf("\n\nadded up frequencies: %05.02f%%\n",addedUpFrequencies);
	}
    } 
    fclose(fptrR);
    printf("\n");
    exit(EXIT_SUCCESS);
}
