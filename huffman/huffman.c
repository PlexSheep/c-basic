#include <errno.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// designed for 512, but other BUFSIZEs work aswell. Don't make it too big or you will get a SEGVAULT
#define BUFSIZE 512

// a single node, only having information for a single byte.
struct Node {
    uint8_t byte;
    size_t occurences;
    unsigned frequencyPriority;
};

// a combination of nodes.
struct Heap {
    struct Heap  *parent, *child0,  *child1;
    struct Node **Nodes;
    bool isRoot;
};

// global vars for Heaps and Nodes.
struct Node* nodes;
struct Heap* heaps;

// initialize our nodes
void initNodes(){
    nodes = malloc(sizeof(struct Node)*256); 
    heaps = malloc(sizeof(struct Heap)*256);    // not sure if i might need more memory for heaps?

    for(int i = 0; i < 256; i++){
        nodes[i].byte = i;
        nodes[i].occurences = 0;
        nodes[i].frequencyPriority = 0;
        heaps[i].isRoot = false;
    }

}

// stolen from stackoverflow
// https://stackoverflow.com/questions/8236/how-do-you-determine-the-size-of-a-file-in-c
off_t fsize(const char *filename) {
    struct stat st;

    if (stat(filename, &st) == 0)
        return st.st_size;

    fprintf(stderr, "Cannot determine size of %s: %s\n", filename,
            strerror(errno));

    return -1;
}

// print help
void helper() {
    printf("huffman compression algorithm implementation for educational "
            "purposes.\n\nSyntax:\nhuffman -f fileToCompress\t\tcompress the "
            "given file\nhuffman -xf fileToDecompress\t\tdecompress the given "
            "file\nhuffman -h\t\t\t\tshow this help\nhuffman -v\t\t\t\tverbose\n");
}

// let the magic happen
int main(int argc, char *argv[]) {
    int opt;
    bool extract_mode = false;
    bool verbose = false;
    bool debug = false;
    char *filestring = NULL;
    off_t filelen;

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
        // open the given file in binary mode
        fptrR = fopen(filestring, "rb");
        if (fptrR == NULL) {
            fprintf(stderr, "The given file does not exist or is unavailable.\n");
            exit(EXIT_FAILURE);
        }
        filelen = fsize(filestring);
        if(verbose) 
            printf("filesize: %ldB\n", filelen);
    } 
    else {
        // empty filestring or filestring is NULL
        fprintf(stderr, "Usage: %s [-dvhx -f] [file]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (extract_mode) {
        printf("extracting is not yet implemented.\n");
        // decompress the file
    }

    else {

        // compress the file
        if (verbose)
            printf("compressing file...\n");

        // frequency analysis
        uint8_t buf [BUFSIZE];

        // dump start of file if debugging
        // FIXME add conditions if the part to print is smaller than 512B
        if(debug){
            printf("[DEBUG]First %d bytes are:\n", BUFSIZE);
            fread(buf, 1, BUFSIZE, fptrR);
            for(int i=0;i<BUFSIZE;i++){
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
        initNodes();
        size_t ret;
        while(!feof(fptrR)){    // count occurences
            ret = fread(buf, 1, BUFSIZE, fptrR);
            if(ret == BUFSIZE){
                // fread success, continue as normal
                // calculate occurences.
                for(int i = 0; i < BUFSIZE; i++){
                    nodes[buf[i]].occurences++;
                }
            }
            else if((ret < BUFSIZE) && (ret >= 0)){
                if(!feof(fptrR)) {
                    // no EOF, but didn't read full buffer. Assuming an error
                    printf("Error while reading file.");
                    exit(EXIT_FAILURE);
                }
                else{
                    // reached EOF, but we might still have more Bytes in Buffer, as not every File has n*BUFSIZE Bytes in it.
                    /*
                     * I don't really get why i need to use ret+BUFSIZE, sounds to me like it produces
                     * a buffer overflow, but somehow it gets those last bytes i couldn't get before and brings
                     * Occurences to 100% in all cases compared against true filelength.
                     * TODO understand why this works!
                     */
                    for(int i = 0; i < ret+BUFSIZE; i++){
                        nodes[buf[i]].occurences++;
                    }
                }
            }
            else{
                printf("Undefined behaviour while reading file.\n");
                exit(EXIT_FAILURE);
            }
            // FIXME, the last 512 bit block is always skipped.
            // fread seems to advance the File pointer by itself, so the following line would skip half of the file.
            // fseek(fptrR, BUFSIZE, SEEK_CUR);
        }

        if(debug){  // show occurences
            printf("Occurences (hex):\n");
            size_t addedUpOccurences = 0;
            for(int i = 0; i < 256; i++){
                if(i%5==0)
                    printf("\n");
                printf("0x%02x: 0x%016llx ", i, nodes[i].occurences);
                addedUpOccurences += nodes[i].occurences;
            }
            printf("\nFilelength: %lldB\nAdded up occurences: %lld\nDifference: %lld\nOccurences in Filelength: %f%%\n",
                    filelen, addedUpOccurences, 
                    filelen - addedUpOccurences, 
                    (float)(100*(addedUpOccurences/(float)filelen)));
        }

        // TODO calculate frequenciePririties

        // TODO build tree using Heaps

        // TODO write Tree and compression to file
    } 

    fclose(fptrR);
    printf("\n");
    if(debug){ // wait for input to end.
        printf("Press Enter to finish.\n");
        getchar();
    }
    exit(EXIT_SUCCESS);
}
