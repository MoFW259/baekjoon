#include <stdio.h>
#include <algorithm>
using namespace std;
int n,m;
char a[251][251];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int sheep=0,wolf=0,rsheep=0,rwolf=0;
void dfs(int x,int y){//dfs
	if(a[x][y]=='#') return;
	if(a[x][y]=='v') wolf++;
	else if(a[x][y]=='o') sheep++;
    a[x][y]='#';
    for(int i=0;i<4;i++){//상하좌우 
        int xx=x+dx[i],yy=y+dy[i];
        if(a[xx][yy]!='#'&&xx>=0&&xx<n&&yy>=0&&yy<m){
        	dfs(xx,yy);
		}
	}
	return;
}
int main(){
	char c[26];
	int t;
	scanf("%d %d",&n,&m); 
	for(int i=0;i<n;i++){
		scanf("%s",&a[i]);
	}for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='#') continue;
			if(a[i][j]=='o'||a[i][j]=='v'){//#이 나오면 dfs실행 
				sheep=0,wolf=0;
				dfs(i,j);
				//printf("%d %d\n",sheep,wolf);
				if(sheep>wolf) rsheep+=sheep;
				else rwolf+=wolf;
			}
		}
	}
	printf("%d %d",rsheep,rwolf);
}