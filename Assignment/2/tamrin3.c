#include<stdio.h>
int main(){
	int i=0,n,b=0,j,p=0,y[100];
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
	i=0;
	while(i<=j){
		if(x[i]==f){
			b=b+1;
			y[p]=i+1;
			p=p+1;
		}
		i=i+1;
	}
	if(b==0){
		printf("The number didn't found");
	}
	if(b>0){
		printf("The number has found\n");
		printf("The count of result is: ");
		printf("%d\n",b);
		printf("There are in the place of: ");
		p=p-1;
		while(p>=0){
			printf("%d,",y[p]);
			p=p-1;
		}
	}
	return 0;
}
			
			
