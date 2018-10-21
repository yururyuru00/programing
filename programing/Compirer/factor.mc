int main()
{
  int n;
  int d;

  putchar('n');
  putchar('=');
  n=getint();

  d=2;
  while (d*d<=n) {
    if (n%d==0) {
      putint(d);
      putchar(' ');
      n=n/d;
    }
    else d=d+1;
  }
  putint(n);
  putchar('\n');
}
