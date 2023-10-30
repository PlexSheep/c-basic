#include <stdio.h>
#include <string.h>

int my_strlen(const char *s) {
  register int len = 0; // try to use a register instead of a stack variable
  while (s[len]) {
    len++;
  }
  return len;
}

int main() {
  char word[] = "hallo\0"; // not NULL terminated

  printf("word is %d long\n", my_strlen(word));
  printf("word is actually %lu long\n", strlen(word));
  printf("success: %b", my_strlen(word) == strlen(word));

  return 0;
}
