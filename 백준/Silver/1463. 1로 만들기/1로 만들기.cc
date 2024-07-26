#include <stdio.h>
#include <algorithm>
using namespace std;
int n,dp[1000001];
int main(){
	scanf("%d",&n); 
	dp[1]=0,dp[2]=1,dp[3]=1;
	for(int i=4;i<=n;i++){
		if(i%2==0&&i%3==0){
			dp[i]=min(min(dp[i/2],dp[i/3]),dp[i-1])+1;
		}else if(i%2!=0&&i%3==0){
			dp[i]=min(dp[i/3],dp[i-1])+1;
		}else if(i%2==0&&i%3!=0){
			dp[i]=min(dp[i/2],dp[i-1])+1;
		}else{
			dp[i]=dp[i-1]+1;
		}
	}printf("%d",dp[n]);
}