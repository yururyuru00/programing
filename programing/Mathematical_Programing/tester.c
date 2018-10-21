#include<stdio.h>
#include<unistd.h>  // sleep()関数のためのライブラリ。

int main(void)
{
  printf("hogehoge row No. 1");
  fflush(stdout);
  sleep(1);  // 次の処理に移る前に1秒待つ。これをしないとすぐに表示が切り替わる。
  printf("\r");
  printf("hogehoge row No. 2");
  fflush(stdout);
  sleep(1);  // 次の処理に移る前に1秒待つ。これをしないとすぐに表示が切り替わる。
  printf("\r");
  printf("hogehoge row No. 3");
  printf("\n");

  return 0;
}

int main(void)
{
  int sum=0;

  return 0;
}
