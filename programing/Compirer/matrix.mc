int main()
{
  int l; int m; int n;
  int i; int j; int k;

  int a[2][3];
  int b[3][4];
  int c[2][4];

  l=2; m=3; n=4;

  a[0][0]=2; a[0][1]=4; a[0][2]=1;
  a[1][0]=3; a[1][1]=2; a[1][2]=5;

  i=0;
  while (i<l) {
    j=0;
    while (j<m) {
      putchar(' ');
      putint(a[i][j]);
      j=j+1;
    }
    putchar('\n');
    i=i+1;
  }

  b[0][0]=2; b[0][1]=4; b[0][2]=1; b[0][3]=5;
  b[1][0]=1; b[1][1]=9; b[1][2]=3; b[1][3]=0;
  b[2][0]=3; b[2][1]=1; b[2][2]=7; b[2][3]=3;

  putchar('\n');
  j=0;
  while (j<m) {
    k=0;
    while (k<n) {
      putchar(' ');
      putint(b[j][k]);
      k=k+1;
    }
    putchar('\n');
    j=j+1;
  }

  i=0;
  while (i<l) {
    k=0;
    while (k<n) {
      c[i][k] = 0;
      j=0;
      while (j<m) {
        c[i][k] = c[i][k]+a[i][j]*b[j][k];
        j=j+1;
      }
      k=k+1;
    }
    i=i+1;
  }

  putchar('\n');
  i=0;
  while (i<l) {
    k=0;
    while (k<n) {
      putchar(' ');
      putint(c[i][k]);
      k=k+1;
    }
    putchar('\n');
    i=i+1;
  }

}
