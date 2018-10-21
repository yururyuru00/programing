#include<stdio.h>

int main(void) {
  for(int i=0; i<=10; i++) {
    char c, dummy;
    printf(">>>\n");
    scanf("%c", &c);
    scanf("%c", &dummy);
    printf("出力%c\n", c);
  }
}
