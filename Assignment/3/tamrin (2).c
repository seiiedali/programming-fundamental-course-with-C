#include <stdio.h>
int main(){
	int i=0,n,sum=0,j=1;
	printf("Enter n: ");
	scanf("%d",&n);
	while(i<n){
		sum=sum+j;
		j=j+2;
		i=i+1;
	}
	printf("Answer: ");
	printf("%d",sum);
	return 0;
}
