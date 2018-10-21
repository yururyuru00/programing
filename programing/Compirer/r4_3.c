#include<stdio.h>

int main(void){
	int i, j;
	double p[10];
  int z[10];
	double x;
	int b = 39;
	double a[10] = {4, 2, 5, 10, 3, 9, 11, 6, 14, 1};
	double c[10] = {22, 10, 24, 40, 14, 43, 50, 30, 69, 5};
	for(i=0; i<=9; i++){
		p[i]=c[i]/a[i];
		for(j=i; j-1>=0; j--){
			if(p[j]<=p[j-1]) {break;}
			else {
				x=p[j];
				p[j]=p[j-1];
				p[j-1]=x;
				x=a[j];
				a[j]=a[j-1];
				a[j-1]=x;
				x=c[j];
				c[j]=c[j-1];
				c[j-1]=x;
			}
		}
	}
	//�\�[�g�I��
	for(i=0; i<=9; i++){
		if(a[i]<=b){
			z[i]=1;
			b=b-a[i];
		}
		else {z[i]=0;}
	}
	printf("a     c      p     y/n\n");
	for(i=0; i<=9; i++) {printf("(%.1f, %.1f, %4.3f %d)\n", a[i], c[i], p[i], z[i]);}

}
