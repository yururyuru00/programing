#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void) {
  char a[6] = "abcde";
  char* token_buffo = malloc(sizeof(char)*(strlen(a)));
  strcpy(token_buffo, a);
  printf("%s\n", a);
  printf("%s\n", token_buffo);
}
