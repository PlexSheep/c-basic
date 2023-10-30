#include <stdio.h>
#include <string.h>

int my_strlen(const char *s) {
  register int len = 0; // try to use a register instead of a stack variable
  while (s[len]) {
    len++;
  }
  return len;
}

void my_strcpy(char *dest, const char *src) {
  register int i = 0;
  while (src[i]) {
    dest[i] = src[i];
    i++;
  }
  // one last time
  dest[i] = src[i];
}

int main() {
  char word[] = "hallo\0"; // not NULL terminated
  char my_buf[6];
  char std_buf[6];

  printf("strlen\n");
  printf("word is %d long\n", my_strlen(word));
  printf("word is actually %lu long\n", strlen(word));
  printf("success: %b\n", my_strlen(word) == strlen(word));

  printf("\nstrcpy\n");
  my_strcpy(my_buf, word);
  strcpy(std_buf, word);
  printf("word: \"%s\"\n", word);
  printf("my_buf: \"%s\"\n", my_buf);
  printf("std_buf: \"%s\"\n", std_buf);
  printf("success: %b\n", 0 == strcmp(my_buf, std_buf));

  return 0;
}
