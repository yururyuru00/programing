int getvint(char var)
{
  int i;
  putchar(var);
  putchar('=');
  return getint();
}

int putvint(char var, int val)
{
  putchar(var);
  putchar('=');
  putint(val);
  putchar('\n');
}

int gcd(int p, int q)
{
  int r;
  r=p%q;
  while (r>0) {
    p=q;
    q=r;
    r=p%q;
  }
  return q;
}

int main()
{
  int n;
  int m;
  int g;
  n=getvint('n');
  m=getvint('m');
  while (m*n>0) {
    if (n>0) {
      g=gcd(n,m);
      putvint('g',g);
    }
    n=getvint('n');
    m=getvint('m');
  }
}
