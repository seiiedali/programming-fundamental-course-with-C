#include<stdio.h>
int main(){
	int i=0,n,b=0,j;
	double x[100],f;
	printf("How many number: ");
	scanf("%d",&n);
	while(i<n){
		printf("Enter the number: ");
		scanf("%lf",&x[i]);
		i=i+1;
	}
	j = i;
	printf("Enter th number that you're searching for:");
	scanf("%lf",& f);
	while(j>=0){
		if(x[j]==f){
			printf("The number has found");
			b=b+1;
			j=0;
		}
		j=j-1;
	}
	if(b==0){
		printf("The number didn't found");
	}
	return 0;
}
			
			
