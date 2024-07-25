#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101][101],ar[101][101],n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt[1001],arrcnt=0,vdfs[1001][1001],res=0;
void dfs(int x,int y){
	if(vdfs[x][y]==0){
        vdfs[x][y]=1;
        for(int i=0;i<4;i++){
			int xx=x+dx[i];
       		int yy=y+dy[i];
            if(a[x][y]==1&&xx>=0&&xx<m&&yy>=0&&yy<n&&a[xx][yy]==1){
            	dfs(xx,yy);
			}
        }
        a[x][y]=0;
    }
}
int main(){
	int t,r;
	int p,q;
	scanf("%d",&t);
	for(int k=1;k<=t;k++){
		scanf("%d %d %d",&n,&m,&r);
		arrcnt=0;
		for(int i=0;i<1001;i++){
			for(int j=0;j<1001;j++){
				vdfs[i][j]=0;
			}
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				a[i][j]=0;
			}
		}
		for(int i=1;i<=r;i++){
			scanf("%d %d",&p,&q);
			a[q][p]=1;
			
		}
		for(int i=0;i<m;i++){
			for(int j=0;j<n;j++){
				if(a[i][j]==1){
					arrcnt++;
					dfs(i,j);
				}
			}
		}
		printf("%d\n",arrcnt);
	}

}