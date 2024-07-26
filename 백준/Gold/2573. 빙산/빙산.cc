#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1001][1001],ar[1001][1001],n,m;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int cnt[100001],arrcnt=0,vdfs[1001][1001],res=0;
void dfs(int x,int y){
	if(vdfs[x][y]==0){
        vdfs[x][y]=1;
        for(int i=0;i<4;i++){
			int xx=x+dx[i];
       		int yy=y+dy[i];
            if(a[x][y]==1 && xx>=0&&xx<n && yy>=0&&yy<m && a[xx][yy]==1){
            	dfs(xx,yy);
			}
        }
        a[x][y]=0;
    }
}
int check[1001][1001];
int checkzero(int x,int y){
	int t=0;
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
       	int yy=y+dy[i];
		if(a[x][y]!=0 && xx>=0&&xx<n && yy>=0&&yy<m && a[xx][yy]==0){
			t++;
		}
	}return t;
} 
int main(){
	int maxx=0;
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
			ar[i][j]=a[i][j];
		}
	}
	for(int k=1;;k++){
		arrcnt=0;
		for(int i=0;i<1001;i++){
			for(int j=0;j<1001;j++){
				vdfs[i][j]=0;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				a[i][j]=ar[i][j];
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]!=0){
					a[i][j]-=checkzero(i,j);
					if(a[i][j]<=0){
						a[i][j]=-1;
					}
					ar[i][j]=a[i][j];
					if(ar[i][j]==-1){
						ar[i][j]=0;
					}
				}
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==0||a[i][j]==-1){
					a[i][j]=0;
				}else{
					a[i][j]=1;
				}
				//printf("%d ",a[i][j]);
			}//printf("\n");
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]==1){
					arrcnt++;
					
					dfs(i,j);
				}
			}
		}
		if(arrcnt>=2){
			printf("%d",k);
			return 0;
		}
		if(arrcnt==0){
			printf("0");
			return 0;
		}
	}
}