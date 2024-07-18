#include <stdio.h>
int n,m,arr[1001]={0},b[1001];
void f(int a,int c){
	if(a>m){
		for(int i=1;i<=m;i++){
			printf("%d ",arr[i]);
		}printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0&&c<i){
			arr[a]=i;
			b[i]=1;
			f(a+1,i);
			b[i]=0;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	f(1,0);
}