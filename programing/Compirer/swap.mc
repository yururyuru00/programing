int swap (int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main ()
{
  int a;
  int b;
  a=10;
  b=20;
  swap(&a,&b);
  putint(a);
  putchar(' ');
  putint(b);
  putchar('\n');
}
