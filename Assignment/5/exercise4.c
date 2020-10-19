#include<stdio.h>
double acker(int m,int n);
int main(){
	int m,n,ans;
	printf("Enter m>=0: ");
	scanf("%d",&m);
	printf("Enter n>=0: ");
	scanf("%d",&n);
	ans=acker(m,n);
	printf("%d",ans);
	return 0;
}
double acker(int m,int n){
	if(m==0){
		return n+1;
	}
	if(n==0){
		return acker(m-1,1);
	}
	return acker(m-1,acker(m,n-1));
}
