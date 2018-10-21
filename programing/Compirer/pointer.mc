int a; 
int c;

int sub ()
{
  int b;
  int c;
  int *p;
  a=1234;
  b=9876;
  p=&a;
  b=(*p)+2;
  p=&c;
  *p=2000;
  putint(a);
  putchar(' ');
  putint(b);
  putchar(' ');
  putint(c);
  putchar('\n');
}

int main ()
{
  sub();
}
