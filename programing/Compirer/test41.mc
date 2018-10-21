int sub(int i)
{
  if (i>0) {
    putint(i);
    putchar('\n');
    sub(i-1);
  }
}

int main()
{
  sub(5);
}
