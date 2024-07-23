#include <iostream>
#include <string>
using namespace std;
int arr[1001][1001];
int ld[1001][1001];
int rd[1001][1001];
char ch[1001];
int main() {
    int r,c;
    int t=0,x=0;
    scanf("%d %d",&r,&c);
    for(int i=0;i<r;i++){
        scanf("%s",ch);
        for(int j=0;j<c;j++){
        	arr[i][j]=ch[j]-'0';
		}
    }
    for(int i=r-1;i>=0;i--){
        for(int j=c-1;j>=0;j--){
            if(arr[i][j]==1){
                ld[i][j]=1;
                rd[i][j]=1;
                if(i+1<r&&j-1>=0){
                	ld[i][j]+=ld[i+1][j-1];
				}
                if(i+1<r&&j+1<c){
                	rd[i][j]+=rd[i+1][j+1];
				}
            }
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(arr[i][j]==1){
                x=min(ld[i][j],rd[i][j]);
                for(int k=x-1;k>=0;k--){
                    if(k<t){
                    	break;
					}if(rd[i+k][j-k]>k&&ld[i+k][j+k]>k){
                        t=max(t, k+1);
                        break;
                    }
                }
            }
        }
    }printf("%d",t);
}