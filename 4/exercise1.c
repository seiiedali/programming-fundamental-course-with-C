#include<stdio.h>
int search(int a[],int start,int end,int key);
int b=0;
int main(){
	int a[100],n,i,s,e,k,h;
	printf("enter key: ");
	scanf("%d",&k);
	printf("enter start: ");
	scanf("%d",&s);
	printf("enter end: ");
	scanf("%d",&e);
	printf("How many values: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter a number: ");
		scanf("%d",&a[i]);
	}
	h=search(a,s,e,k);
	printf("%d",h);
	return 0;
}
int search(int a[],int start,int end,int key){
	if(a[start]==key && start<=end){
		b++;
	}
	if(start==end){
	return b;
}
	search(a,start+1,end,key);
}
