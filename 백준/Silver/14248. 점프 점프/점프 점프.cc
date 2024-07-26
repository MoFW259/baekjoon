#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
int a[100001];

int cnt=0,v[100001];
void dfs(int x){//dfs
	if(v[x]==0){
		
		v[x]=1;
		cnt++;
		int dx[2]={a[x],-1*a[x]};
	    for(int i=0;i<2;i++){//좌우 
	        int xx=x+dx[i];
			//printf("%d ",xx);
	        if(xx>0&&xx<=n&&v[xx]==0){
	        	dfs(xx);
			}
		}
	}
}
int main(){
	int t;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}scanf("%d",&m);
	dfs(m);
	printf("%d",cnt);
}