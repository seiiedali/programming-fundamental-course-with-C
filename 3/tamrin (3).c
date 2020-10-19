#include<stdio.h>
int main(){
	int i=1,j,sum,n;
	printf("Enter the number: ");
	scanf("%d",&n);
	while(i<=n-1){
		j=1;
		sum=0;
		while(j<=(i/2)){
			if((i/j)*j==i){
				sum=sum+j;
			}
			j=j+1;
		}
		if(sum==i){
			printf("%d\n",i);
		}
		i=i+1;
	}
	return 0;
}		
