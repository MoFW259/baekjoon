#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101][101],ar[101][101],n;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt[1001],arrcnt=0,vdfs[1001][1001],res=0;
void dfs(int x,int y){
	if(vdfs[x][y]==0){
        vdfs[x][y]=1;
        for(int i=0;i<4;i++){
			int xx=x+dx[i];
       		int yy=y+dy[i];
            if(a[x][y]==1 && xx>=0&&xx<n && yy>=0&&yy<n && a[xx][yy]==1){
            	dfs(xx,yy);
			}
        }
        a[x][y]=0;
    }
}
int main(){
	int maxx=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			ar[i][j]=a[i][j];
			maxx=max(maxx,a[i][j]);
		}
	}
	for(int k=0;k<=maxx;k++){
		arrcnt=0;
		for(int i=0;i<1001;i++){
			for(int j=0;j<1001;j++){
				vdfs[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				a[i][j]=ar[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]<=k){
					a[i][j]=0;
				}else{
					a[i][j]=1;
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==1){
					arrcnt++;
					dfs(i,j);
				}
			}
		}
		res=max(res,arrcnt);
	}
	printf("%d",res);
}