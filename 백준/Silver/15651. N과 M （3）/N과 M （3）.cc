#include <stdio.h>
int n,m,arr[1001],b[3];
void f(int a){
	if(a>m){
		for(int i=1;i<=m;i++){
			printf("%d ",arr[i]);
		}printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		//if(b[i]==0){
			arr[a]=i;
			//b[i]=1;
			f(a+1);
			//b[i]=0;
		//}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	f(1);
}