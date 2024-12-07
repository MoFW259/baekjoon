#include <stdio.h>
int main(){
	int n,r=0,longest;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			longest=n-i-j;
			//printf("%d %d %d\n",i,j,longest);
			if(j>longest) break;
			if(i+j>longest){
				r++;
			}
		}
	}
	printf("%d",r);
}