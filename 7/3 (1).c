#include<stdio.h>
void check_diagonal(int [][20],int);
int main(){
	int a[20][20],i,j,n;
	printf("Enter n for rows and columns: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter value for a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	check_diagonal(a,n);
	return 0;
}
void check_diagonal(int a[][20],int n){
	int i,j,b=0;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i!=j){
				if(a[i][j]!=0){
					b=1;
				}
			}
		}
	}
	if(b==0){
		printf("The matris is diagonal");
	}
	if(b==1){
		printf("The matris isn't diagonal");
	}
}

			
	
	
