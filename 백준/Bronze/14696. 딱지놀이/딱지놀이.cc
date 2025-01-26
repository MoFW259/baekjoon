#include<stdio.h>
int main(){
	int n;
	int a;
	int b;
	int x[4]={};
	int y[4]={};
	int t;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<4;j++){
			x[j]=0;
			y[j]=0;
		}
		scanf("%d",&a);
		for(int j=0;j<a;j++){
			scanf("%d",&t);
			x[t-1]++;
		}
		scanf("%d",&b);
		for(int j=0;j<b;j++){
			scanf("%d",&t);
			y[t-1]++;
		}
		for(int j=3;j>=0;j--){
			if(x[j]>y[j]){
				printf("A\n");
				break;
			}
			else if(x[j]<y[j]){
				printf("B\n");
				break;
			}
			else if(j==0){
				printf("D\n");
			}
		}
	}
}
