int main()
{
  int s;
  int n;
  int i;
  putchar('n');
  putchar('=');
  n = getint();
  s=0;
  i=1;
  while (i<=n) {
    s=s+i;
    i=i+1;
  }
  putchar('s');
  putchar('=');
  putint(s);
  putchar('\n');
}
