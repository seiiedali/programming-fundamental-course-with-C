#include<stdio.h>
double comb(int n,int m);
int main(){
	int m,n,ans;
	printf("Enter n: ");
	scanf("%d",&n);
	printf("Enter m: ");
	scanf("%d",&m);
	ans=comb(n,m);
	printf("%d",ans);
	return 0;
}
double comb(int n,int m){
	if(n==m){
		return 1;
	}
	if(m==0){
		return 1;
	}
	return comb(n-1,m)+comb(n-1,m-1);
}
