#include <stdio.h>
#include <algorithm>
#include <queue>
using namespace std;
int n,m;
char a[251][251];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int rsheep=0,rwolf=0;
void bfs(int x,int y){
	queue<pair <int,int> > q;
	q.push({x,y});
	int sheep=0,wolf=0;
	if(a[x][y]=='v') wolf++;
	else if(a[x][y]=='o') sheep++;
    a[x][y]='#';
    while(!q.empty()){
		int nx=q.front().first,ny=q.front().second;
	    q.pop();
    	for(int i=0;i<4;i++){//상하좌우 
	        int xx=nx+dx[i],yy=ny+dy[i];
	        if(a[xx][yy]!='#'&&xx>=0&&xx<n&&yy>=0&&yy<m){
	        	if(a[xx][yy]=='v') wolf++;
	        	else if(a[xx][yy]=='o') sheep++;
	        	a[xx][yy]='#';
	        	q.push({xx,yy});
			}
		}
	}
	if(sheep>wolf) rsheep+=sheep;
	else rwolf+=wolf;
}
int main(){
	char c[26];
	int t;
	scanf("%d %d",&n,&m); 
	for(int i=0;i<n;i++){
		scanf("%s",&a[i]);
	}for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='o'||a[i][j]=='v'){//#이 나오면 dfs실행 
				bfs(i,j);
				
			}
		}
	}
	printf("%d %d",rsheep,rwolf);
}