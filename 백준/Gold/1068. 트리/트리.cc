#include <stdio.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <queue>
using namespace std;
vector <int> a[101];
int cnt=0,r,m;
int vdfs[1001];
int dfs(int v){
    int mid=0,las=0;
    for(int i:a[v]){
        if(i==m) continue;
        mid+=dfs(i);
    	las++;
    }if(las==0){
        return 1;
	}
	return mid;
}
int main(){
	int n,v,b;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(v==-1){
			r=i;
		}else{
			a[v].push_back(i);
		}
	}scanf("%d",&m);
	if(m==r){
		printf("0");
		return 0;
	}
	printf("%d",dfs(r));
}