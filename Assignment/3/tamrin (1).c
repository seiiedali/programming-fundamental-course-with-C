#include<stdio.h>
int main(){
	int i=0,n,j=0;
	double x[100];
	printf("How many salary: ");
	scanf("%d",&n);
	while(i<n){
		printf("Enter the salary(toman): ");
		scanf("%lf",&x[i]);
		if(x[i]>=1000 && x[i]<=2000){
			x[i]=x[i]-100;
		}
		if(x[i]>2000){
			x[i]=x[i]-((x[i]-2000)*0.5+100);
		}
		i=i+1;
	}
	j=i-1;
	i=0;
	printf("The pure salary on sort of entered:\n");
	while(i<=j){
		printf("%lf",x[i]);
		printf("\n");
		i=i+1;
	}
	return 0;
}
