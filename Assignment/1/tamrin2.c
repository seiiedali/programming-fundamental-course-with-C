#include<stdio.h>
int main(){
	int a,b,a1=0,c1=0,c2=0,sum=0;
	printf("Enter a: ");
	scanf("%d",&a);
	printf("Enter b: ");
	scanf("%d",&b);
	a1=a1+a;
	while(a1>0){
		a1=a1/10;
		c1=c1+1;
	}
	while(c2<c1){
		b=b*10;
		c2=c2+1;
	}
	sum=sum+a+b;
	printf("answer:%d",sum);
	return 0;
}
