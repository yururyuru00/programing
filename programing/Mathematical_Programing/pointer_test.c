#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define BUS_MAX_SIZE 100

typedef struct {
  char which_bus[2]; //そのバスがAかBか
  int capasity; //収容人数
  int profits; //利益
  int cost; //費用
  int riding_time; //客を乗せるのにかかる時間
} bus_detail_t;

typedef struct {
  int bus_size; //出したバスの合計数
  bus_detail_t bus[BUS_MAX_SIZE];
} bus_t;

//関数軍の一覧
bus_t* bus_new();
bool bus_register(bus_t* b);
void bus_print(bus_t* b);

int main(void) {
  bool boo = true;
  bus_t* b = bus_new();
  while(boo==true) boo = bus_register(b);
  bus_print(b);
}

bus_t* bus_new() {
  bus_t* x = (bus_t* )malloc(sizeof(bus_t));
  x->bus_size=0;
  return x;
}

bool bus_register(bus_t* b) {
  char bus[2];
  printf("どのバスを出しますか?(A/B/no)---\n");
  scanf("%s", bus);

  //入力内容によって登録内容を場合分け
  if(bus[0]=='A' && bus[1]=='\0') {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].capasity=100;
    b->bus[b->bus_size].profits=200;
    b->bus[b->bus_size].cost=140;
    b->bus[b->bus_size].riding_time=3;
    (b->bus_size)++;
    return true;
  }
  else if(bus[0]=='B' && bus[1]=='\0') {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].capasity=160;
    b->bus[b->bus_size].profits=270;
    b->bus[b->bus_size].cost=170;
    b->bus[b->bus_size].riding_time=4;
    (b->bus_size)++;
    return true;
  }
  else if(strncmp(bus, "no", 2)==0) {return false;}
  else {
    printf("選択肢は'A''B''n'のどれかにしてください");
    return true;
  }
}

void bus_print(bus_t* b) {
  int size = b->bus_size;
  if(size>0) {
    printf("選択された1~%d番目のバスの内容は>>>\n", size);
    printf("どのバス　人数制限　利益　出す費用　搭乗時間\n");
    for(int i=0; i<size; i++) printf("%d   %s 　　　 %d       %d    %d        %d\n", i+1, b->bus[i].which_bus, b->bus[i].capasity, b->bus[i].profits, b->bus[i].cost, b->bus[i].riding_time);
  }
  else {printf("まだバスが登録されていません\n");}
}
