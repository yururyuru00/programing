#include<stdio.h>
#include<string.h>
#include<stdbool.h>

void boolchange(bool* b);

int main(){
  int b=1;
  int* a;
  a = &b;
  float d = (*a)/(double)10;
  printf("%f\n", d);
}
