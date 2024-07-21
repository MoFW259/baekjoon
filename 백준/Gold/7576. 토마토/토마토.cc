#include <stdio.h>
#include <queue>
#include <iostream>
#include <cstring>
using namespace std;

int arr[1002][1002];
int xfour[5]={0,0,1,0,-1},yfour[5]={0,1,0,-1,0};
int cnt=0;
struct ihatebfs{
	int x,y;
};
queue <ihatebfs> q;
void bfs(){
	while(!q.empty()){
		int x=q.front().x;
		int y=q.front().y;
		q.pop();
		for(int i=1;i<=4;i++){
			int xx=x+xfour[i];
			int yy=y+yfour[i];
			if(arr[xx][yy]==0){
            	arr[xx][yy]=arr[x][y]+1;
            	q.push({xx,yy});
			}
		}
	}
	
}
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=0;i<=m+1;i++){
		for(int j=0;j<=n+1;j++){
			arr[i][j]=-1;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
			if(arr[i][j]==1){
				q.push({i,j});
			}
		}
	}bfs();
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(arr[i][j]==0){
				printf("-1");
				return 0;
			}
			if(arr[i][j]>cnt){
				cnt=arr[i][j];
			}
		}
	}printf("%d\n",cnt-1);
}