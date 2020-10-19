#include <stdio.h>
int main(){
	int ans=0,sum=0,n,i=1;
	printf("Enter n: ");
	scanf("%d",&n);
	while(i<=n){
		sum=sum+i*i;
		i=i+1;
	}
	ans = sum/i;
	printf("answer:%d",ans);
	return 0;
}
