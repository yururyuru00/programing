int main()
{
  int engine;
  int number;
  putchar('?');
  engine=getint();
  if (engine>=2000) number=33;
  else              number=55;
  putint(number);
  putchar('\n');
  number = 55;
  if (engine>=2000) number=33;
  putint(number);
  putchar('\n');
}
