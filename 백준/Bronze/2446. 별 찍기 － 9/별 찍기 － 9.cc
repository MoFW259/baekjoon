#include <stdio.h>
int main(){
	int n;
	scanf("%d",&n);
	for(int i=2;i<=n*2;i+=2){
		for(int j=2;j<=i/2;j++){
			printf(" ");
		}
		for(int j=n*2;j>=i;j--){
			printf("*");
		}
		printf("\n");
	}
	for(int i=n*2-2;i>=1;i-=2){
		for(int j=2;j<=i/2;j++){
			printf(" ");
		}
		for(int j=n*2;j>=i;j--){
			printf("*");
		}
		printf("\n");
	}
}