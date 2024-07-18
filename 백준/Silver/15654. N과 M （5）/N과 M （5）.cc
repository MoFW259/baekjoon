#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m,arr[1001]={0},b[1001],sc[1001];
void f(int a){
	if(a>m){
		for(int i=1;i<=m;i++){
			printf("%d ",arr[i]);
		}printf("\n");
		return;
	}
	for(int i=1;i<=n;i++){
		if(b[i]==0){
			arr[a]=sc[i];
			b[i]=1;
			f(a+1);
			b[i]=0;
		}
	}
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&sc[i]);
	}
	sort(sc+1,sc+n+1);
	f(1);
}