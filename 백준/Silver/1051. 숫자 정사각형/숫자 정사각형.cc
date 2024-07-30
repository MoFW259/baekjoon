#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int n,m,arr[52][52],t=0;
	char c[52];
	scanf("%d %d",&n,&m);
	for(int i=0;i<=51;i++){
		for(int j=0;j<=51;j++){
			arr[i][j]=-1;
		}
	}
	for(int i=0;i<n;i++){
		scanf("%s",c);
		for(int j=0;j<m;j++){
			arr[i][j]=c[j]-'0';
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=1;k+i<=n&&k+j<=m;k++){
				if(arr[i][j]==arr[i+k-1][j]&&arr[i][j]==arr[i][j+k-1]&&arr[i][j]==arr[i+k-1][j+k-1]){
					t=max(t,k);
				}
			}
		}
	}printf("%d",t*t);
}