#include<stdio.h>
void mat_rot(int [][20],int[][20],int);
int main(){
	int a[20][20],b[20][20],n,i,j;
	printf("Enter n for rows and clumns: ");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Enter value for a[%d][%d]: ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	mat_rot(a,b,n);
	printf("matris is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
	printf("matris after rotare is: \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%d\t",b[i][j]);
		}
		printf("\n");
	}
	return 0;
}
void mat_rot(int a[][20],int b[][20],int n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			b[j][n-i-1]=a[i][j];
		}
	}
}
