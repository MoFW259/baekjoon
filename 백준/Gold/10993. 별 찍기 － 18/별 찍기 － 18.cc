#include <stdio.h>
#include <math.h>
char dp[2051][2051];
void iatejaegui/*yummy*/(int x,int y,int n) {
    if (n==1) {
        dp[x][y]='*';
        return;
    }
    int xx=pow(2,n+1)-3;
    int yy=pow(2,n)-1;

    if(n%2!=0){
        for(int i=0;i<xx;i++){
            dp[x+yy-1][y+i]='*';
        }
        for(int i=0;i<yy;i++){
            dp[x+i][y+xx/2-i]='*';
            dp[x+i][y+xx/2+i]='*';
        }
        int t=pow(2,n-1);
        iatejaegui(x+yy/2,y+t,n-1);
    }else{
        for(int i=0;i<xx;i++){
            dp[x][y+i]='*';
        }
        for(int i=0;i<yy;i++){
            dp[x+i+1][y+i+1]='*';
            dp[x+i+1][y+xx-i-2]='*';
        }
        int t=pow(2,n-1);
        iatejaegui(x+1,y+t,n-1);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<=2050;i++){
        for(int j=0;j<=2050;j++){
            dp[i][j]=' ';
        }
    }
    iatejaegui(0,0,n);
    int xx=pow(2,n)-1;
    int yy=pow(2,n+1)-3;
    for(int i=0;i<xx;i++){
    	if(n%2==1){
    		for(int j=0;j<yy-xx+i+1;j++){
        	    printf("%c",dp[i][j]);
      		}printf("\n");
      		continue;
		}
        for(int j=0;j<yy-i;j++){
            printf("%c",dp[i][j]);
        }
        printf("\n");
    }
}