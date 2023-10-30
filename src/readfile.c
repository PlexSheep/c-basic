#include <stdlib.h>
#include <stdio.h>
 
int main(int argc, char** argv)
{
   if (argc != 2) {
      printf("usage: %s FILE", argv[0]);
      exit(1);
   }
   char* filename = argv[1];
   char buf[2];
   FILE *fp;
    
   if ((fp = fopen(filename, "rb")) == NULL)
   {
      printf("Unable to open file: %s\n", filename);
      return EXIT_FAILURE;
   }
    
   if (fread(buf, 1, 2, fp) == 2)
   {
      printf("%02x %02x\n", (int) buf[0], (int) buf[1]);
   }
    
   fclose(fp);
   return 0;
}
