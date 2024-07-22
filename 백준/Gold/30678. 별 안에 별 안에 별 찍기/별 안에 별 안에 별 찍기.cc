#include <stdio.h>
#include <math.h>
char notdp[4000][4000];
void ihatejaegui(int i,int j,int n){

	if(n==1){
		notdp[i][j]='*';
		//printf("%d %d\n",i,j);
		return;
	}
	n/=5;
	ihatejaegui(i,j,n);
	ihatejaegui(i+n,j,n);
	ihatejaegui(i+n+n,j-n-n,n);
	ihatejaegui(i+n+n,j-n,n);
	ihatejaegui(i+n+n,j,n);
	ihatejaegui(i+n+n,j+n,n);
	ihatejaegui(i+n+n,j+n+n,n);
	ihatejaegui(i+n+n+n,j-n,n);
	ihatejaegui(i+n+n+n,j,n);
	ihatejaegui(i+n+n+n,j+n,n);
	ihatejaegui(i+n+n+n+n,j-n,n);
	ihatejaegui(i+n+n+n+n,j+n,n);
	return;
}
int main(){
	int n,t;
	scanf("%d",&t);
	if(t==0){
		printf("*");
		return 0;
	}
	n=(int)pow(5,t);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			notdp[i][j]=' ';
		}
	}
	ihatejaegui(0,(n-1)/2,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%c",notdp[i][j]);
		}
		printf("\n");
	}
}