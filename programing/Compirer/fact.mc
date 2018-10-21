int fact(int k)
{
  if (k==0) return 1;
  else      return k*fact(k-1);
}

int main()
{
  int n;
  int f;
  putchar('n');
  putchar('=');
  n = getint();
  f = fact(n);
  putint(n);
  putchar('!');
  putchar('=');
  putint(f);
  putchar('\n');
}

