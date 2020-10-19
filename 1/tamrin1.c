#include<stdio.h>
int main(){
	int c1=0,c2=0,c3=0,p,n,a;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter n: ");
	scanf("%d",&n);
	p=n-1;
	while(c1<n){
		printf("|");
		while(c2<p){
			printf(" ");
			c2=c2+1;
		}
		c2=0;
		p=p-1;
		while(c3<a){
			printf("*");
			c3=c3+1;
		}
		c3=0;
		printf("\n");
		c1=c1+1;
	}
	return 0;
}
