#include <stdio.h>
#include <string.h>

int my_strlen(const char *s) {
  int len = 0;
  while (s[len] != 0) {
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
