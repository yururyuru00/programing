#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<assert.h>
#include<stdbool.h>
#include<string.h>
#include"free_research.h"

bus_t* bus_new();
void bus_register(bus_t* b, int* identifier, int i);
void quest_add_bus(bus_t* b, int* identifier, int i);
void add_bus_register(bus_t* b, int* identifier, int i);
void collect_person(bus_t* b, int* identifier, int* person, int first_bus, int last_bus, int opp_loss, int time, FILE* outputfile);
void bus_print(bus_t* b, FILE* outputfile);
void profits_cal_print(bus_t* b, int opp_loss, int pass_time, FILE* outputfile);
int Getrandom(int i);
void time_printer(int i, int identifier, FILE* outputfile);
void simulation(bus_t* b, int times, int* identifier, FILE* outputfile);
void warning_bussize(bus_t* b, int n, int time, int first_bus, int last_bus);
void abnormal_error(char* msg);


int a_limit, b_limit;
double ave_f=0.0;


int main(void) {
  //ファイルオープン
  FILE* outputfile;
  outputfile = fopen("out.txt", "w");
  if(outputfile==NULL) {
    printf("cannot open\n");
    exit(1);
  }

  srand((unsigned)time(NULL));
  int identifier;
  int j, i, n, first_bus, last_bus;
  int person=0;
  int opp_loss=0;

  //バス列初期化
  bus_t* b = bus_new();

  //バスの本数の質問、入力
  printf("バスを何本出す予定ですか？---");
  scanf("%d", &n);

  //traceモード
  for(i=0; i<=18; i++) {
    //この群で行列の生成
    person = person + ((int)Getrandom(i));
    time_printer(i, TERM, outputfile);
    for(j=1; j<=(person/10); j++) printf("|");
    printf(" %d人\n", person);

    //ここでバスを追加するかどうか聞きそれに対応してバス列追加
    first_bus = b->bus_size; //この変数はバスを追加していく際に最初のバスが何番目だったかを確保するため
    bus_register(b, &identifier, i);
    last_bus = b->bus_size; //
    warning_bussize(b, n, i, first_bus, last_bus);

    //返事がstopならシミュレーション停止、それ以外ならバスが人を回収
    collect_person(b, &identifier, &person, first_bus, last_bus, opp_loss, i, outputfile);

    //回収後の残り待ち行列の積分 これの合計値が機会損失になる
    opp_loss += person;

    //この群で回収後の行列の生成
    time_printer(i, TERM, outputfile);
    for(j=1; j<=(person/10); j++) printf("|");
    printf("　%d人\n\n", person);
    sleep(0);
  }
  bus_print(b, outputfile);
  //費用,機会損失,利益の算出,更に出力
  fprintf(outputfile, "平均機会損失    平均ストレス　　　費用(万)      利益(万)     目的関数\n");
  profits_cal_print(b, opp_loss, i, outputfile);

  //シミュレーションモード
  simulation(b, 10, &identifier, outputfile);

  fclose(outputfile);
  return 0;
}


void simulation(bus_t* b, int times, int* identifier, FILE* outputfile) {
  int person, opp_loss, i, j;
  *identifier = TRACE;
  for(i=0; i<times; i++) {
    person=0;
    opp_loss=0;
    for(j=0; j<=18; j++) {
      person = person + ((int)Getrandom(j));

      collect_person(b, identifier, &person, 0, 0, opp_loss, j, outputfile);
      /*while(b->bus[k].pass_time==j && k<(b->bus_size)) {
        if(person>=b->bus[k].capasity) {person -= b->bus[k].capasity;}
        else {person=0;}
        k++;
      }*/
      opp_loss += person;
    }
    profits_cal_print(b, opp_loss, j, outputfile);
  }
  fprintf(outputfile, "%.2lf\n", ave_f/(double)(times+1));
}


void warning_bussize(bus_t* b, int n, int time, int first_bus, int last_bus) {
  if(time==0) {
    a_limit = ((int)n*0.7);
    b_limit = n - a_limit;
  }
  else {
    for(int i=first_bus; i<last_bus; i++) {
      printf("%d ", i);
      if(strncmp(b->bus[i].which_bus, "A", 1)==0) {
        a_limit=a_limit-1;
      }
      else if(strncmp(b->bus[i].which_bus, "B", 1)==0) {
        b_limit=b_limit-1;
      }
      else abnormal_error("バスが登録されていません");
    }
  }

  if(a_limit<0 || b_limit<0) abnormal_error("バスが足りません");
  else printf("バスA残り:%d バスB残り:%d\n", a_limit, b_limit);
}


void abnormal_error(char* msg) {
  fprintf(stderr, "%s\n", msg);
  exit(0);
}



int Getrandom(int i) {
  int f = 10*sqrt(i);
  if(i==0) return 0;
  else {return ((int)f + (rand()%(f)));}
}


void time_printer(int i, int identifier, FILE* outputfile) {
  //i1メモリで5分
  //15時からスタート
  int h, m;
  h = (i*5)/60;
  m = (i*5)%60;

  if(identifier==TERM) {
    if(m<10) printf("%d:0%d ", 15+h, 0+m);
    else printf("%d:%d ", 15+h, 0+m);
  }
  else {
    if(m<10) fprintf(outputfile, "%d:0%d ", 15+h, 0+m);
    else fprintf(outputfile, "%d:%d ", 15+h, 0+m);
  }
}


bus_t* bus_new() {
  bus_t* b = (bus_t* )malloc(sizeof(bus_t));
  assert(b!=NULL);
  b->bus_size=0;
  return b;
}


void bus_register(bus_t* b, int* identifier, int i) {
  char bus[5];

  printf("どのバスを出しますか?(A/B/no/stop)---");
  scanf("%s", bus);

  if(bus[0]=='A' && bus[1]=='\0') {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].pass_time=i;
    b->bus[b->bus_size].capasity=100;
    b->bus[b->bus_size].profits=30000;
    b->bus[b->bus_size].cost=5000;
    b->bus[b->bus_size].riding_time=5;
    (b->bus_size)++;
    *identifier = RIDE;
  }
  else if(bus[0]=='B' && bus[1]=='\0') {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].pass_time=i;
    b->bus[b->bus_size].capasity=150;
    b->bus[b->bus_size].profits=40000;
    b->bus[b->bus_size].cost=6500;
    b->bus[b->bus_size].riding_time=10;
    (b->bus_size)++;
    *identifier = RIDE;
  }
  else if(strncmp(bus, "no\0", 3)==0) {*identifier = NORIDE;}
  else if(strncmp(bus, "stop\0", 5)==0) {*identifier = STOP;}
  else {
    printf("A/B/no/stop のどれかにしてください! ");
    bus_register(b, identifier, i);
  }

  //バスの追加
  if(*identifier==RIDE) {quest_add_bus(b, identifier, i);}
  else {;}
}


void quest_add_bus(bus_t* b, int* identifier, int i) {
  char reply[4];

  printf("バスを追加しますか?(yes/no)---");
  scanf("%s", reply);
  if(strncmp(reply, "no\0", 3)==0) {;}
  else if(strncmp(reply, "yes\0", 4)==0) {add_bus_register(b, identifier, i);}
  else {
    printf("yes/no のどれかにしてください! ");
    quest_add_bus(b, identifier, i);
  }
}


void add_bus_register(bus_t* b, int* identifier, int i) {
  char bus[2];
  printf("どちらのバスを出しますか?(A/B)---");
  scanf("%s", bus);

  if(strcmp(bus, "A\0")==0) {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].pass_time=i;
    b->bus[b->bus_size].capasity=100;
    b->bus[b->bus_size].profits=30000;
    b->bus[b->bus_size].cost=5000;
    b->bus[b->bus_size].riding_time=5;
    (b->bus_size)++;
    *identifier = ADD;
    quest_add_bus(b, identifier, i);
  }
  else if(strcmp(bus, "B\0")==0) {
    strcpy(b->bus[b->bus_size].which_bus, bus);
    b->bus[b->bus_size].pass_time=i;
    b->bus[b->bus_size].capasity=150;
    b->bus[b->bus_size].profits=40000;
    b->bus[b->bus_size].cost=6500;
    b->bus[b->bus_size].riding_time=10;
    (b->bus_size)++;
    *identifier = ADD;
    quest_add_bus(b, identifier, i);
  }
  else {
    printf("A/B のどちらかにしてください! ");
    add_bus_register(b, identifier, i);
  }
}


void collect_person(bus_t* b, int* identifier, int* person, int first_bus, int last_bus, int opp_loss, int time, FILE* outputfile) {
  int i;
  int x;

  if(*identifier==RIDE) {
    if(b->bus[first_bus].capasity<=(*person)) {
      *person = ((*person)-(b->bus[first_bus].capasity));
      b->bus[first_bus].occupancy=1;
    }
    else {
      b->bus[first_bus].occupancy = (*person)/(double)(b->bus[first_bus].capasity);
      (*person) = 0;
    }
  }
  else if(*identifier==ADD) {
    for(i=first_bus; i<last_bus; i++) {
      if(b->bus[i].capasity<=(*person)) {
        *person = ((*person)-(b->bus[i].capasity));
        b->bus[i].occupancy=1;
        //printf("%d %d\n", *person, b->bus[i].capasity);
      }
      else {
        b->bus[i].occupancy = (*person)/(double)(b->bus[i].capasity);
        *person = 0;
        //printf("%d %d\n", *person, b->bus[i].capasity);
      }
    }
  }
  else if(*identifier==NORIDE) {;}
  else if(*identifier==TRACE) {
    if(time==0) {x=0;}
    else {;}
    while(b->bus[x].pass_time==time) {
      if(b->bus[x].capasity<=(*person)) {
        *person = ((*person)-(b->bus[x].capasity));
        b->bus[x].occupancy=1;
      }
      else {
        b->bus[x].occupancy = (*person)/(double)(b->bus[x].capasity);
        *person = 0;
      }
      x++;
    }
    //printf("%d   %d   %d   %d   %.2lf\n", x, time, b->bus[x].pass_time, *person, b->bus[x-1].occupancy);
  }
  else {
    bus_print(b, outputfile);
    profits_cal_print(b, opp_loss, time, outputfile);
    exit(0);
  }
}


void bus_print(bus_t* b, FILE* outputfile) {
  int size = b->bus_size;
  if(size>0) {
    fprintf(outputfile, "選択された1~%d番目のバスの内容は>>>\n", size);
    fprintf(outputfile, "出発時間  　バス    人数制限　利益(万)　 出す費用(万)   搭乗時間   乗車率\n");
    for(int i=0; i<size; i++) {
      fprintf(outputfile, "%d   ", i+1);
      time_printer(b->bus[i].pass_time, NOTTERM, outputfile);
      fprintf(outputfile, "      %s 　　　%d       %.2f　　    %.2lf　　        %d   %f\n", b->bus[i].which_bus, b->bus[i].capasity, ((double)b->bus[i].profits/10000), ((double)b->bus[i].cost/10000), b->bus[i].riding_time, b->bus[i].occupancy);
    }
  }
  else {printf("まだバスが登録されていません\n");}
}


void profits_cal_print(bus_t* b, int opp_loss, int pass_time, FILE* outputfile) {
double profit_sum=0.0;
int cost_sum=0;
int stress=0;

  for(int i=0; i<(b->bus_size); i++) {
    profit_sum += ((double)(b->bus[i].profits*b->bus[i].occupancy));
    cost_sum += (b->bus[i].cost);
    if(b->bus[i].occupancy>=0.5) stress += ((int)100*(b->bus[i].occupancy-0.5));
    else ;
  }
double ave_opp_loss = ((double)opp_loss/pass_time);
double ave_stress = ((double)stress/pass_time);
double f = -1 * (0.1*ave_opp_loss + 0.1*ave_stress + cost_sum/10000) + profit_sum/10000;
fprintf(outputfile, "%.2lf           %.2lf             %.2lf        %.2lf    %.2lf\n", ave_opp_loss, ave_stress, ((double)cost_sum/10000), ((double)profit_sum/10000), f);
ave_f += f;
}
