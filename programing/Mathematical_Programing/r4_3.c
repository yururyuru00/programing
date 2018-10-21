#include<stdio.h>

int main(void){
	int i, j;
	int p[10]={0,0,0,0,0,0,0,0,0,0};
        int z[10];
	int x;
	int b = 39;
	int a[10] = {4, 2, 5, 10, 3, 9, 11, 6, 14, 1};
	int c[10] = {22, 10, 24, 40, 14, 43, 50, 30, 69, 5};
	p[0]=c[0]/a[0];
	for(i=1; i<=9; i++){
		p[i]=c[i]/a[i];
		for(j=i; j-1>=0; j++){
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
				c[j-1]=x;a
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
	for(i=0; i<=9; i++) {printf("%d ", z[i]);}

}
