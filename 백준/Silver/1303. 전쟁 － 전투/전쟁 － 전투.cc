#include <stdio.h>
#include <algorithm>
using namespace std;
char a[101][101];
int n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt[10000001],arrcnt=0,vdfs[101][101];
void wdfs(int x,int y){
	if(vdfs[x][y]==0){
		cnt[arrcnt]++;
        vdfs[x][y]=1;
        for(int i=0;i<4;i++){
        	int xx=x+dx[i];
        	int yy=y+dy[i];
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&a[xx][yy]=='W'){
            	wdfs(xx,yy);
			}
        }
        a[x][y]='0';
    }
}void bdfs(int x,int y){
	if(vdfs[x][y]==0){
		cnt[arrcnt]++;
        vdfs[x][y]=1;
        for(int i=0;i<4;i++){
        	int xx=x+dx[i];
        	int yy=y+dy[i];
            if(xx>=0&&xx<m&&yy>=0&&yy<n&&a[xx][yy]=='B'){
            	bdfs(xx,yy);
			}
        }
        a[x][y]='0';
    }
}
int main(){
	int w=0,b=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%s",&a[i]);
	}for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(a[i][j]=='W'){
				arrcnt++;
				wdfs(i,j);
				int temp=cnt[arrcnt]*cnt[arrcnt];
				w+=temp;
				//printf("%d\n",temp);
			}else if(a[i][j]=='B'){
				arrcnt++;
				bdfs(i,j);
				int temp=cnt[arrcnt]*cnt[arrcnt];
				b+=temp;
			}
		}
	}printf("%d %d",w,b);
}