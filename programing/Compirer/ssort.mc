int a[8];

int ssort(int n)
{
  int i;
  int j;
  int min;
  int min_j;
  i=0;
  while(i<n-1) {
    min_j=i;
    min=a[i];
    j=i+1;
    while(j<n) {
      if (a[j]<min) {
        min = a[j];
        min_j = j;
      }
      j=j+1;
    }
    a[min_j] = a[i];
    a[i] = min;
    i=i+1;
  }
}

int print_a(int n)
{
  int i;
  i=0;
  while(i<n) {
    putchar(' ');
    putint(a[i]);
    i=i+1;
  }
  putchar('\n');
}

int main()
{
  int n;
  n=8;
  a[0]=8; a[1]=1; a[2]=4; a[3]=7; 
  a[4]=2; a[5]=4; a[6]=5; a[7]=6; 
  print_a(n);
  ssort(n);
  print_a(n);
}

