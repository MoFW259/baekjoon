#include <stdio.h>
int main(){
	long long int n,dp[117];
	scanf("%lld",&n);
	dp[1]=1;dp[2]=1;dp[3]=1;
	for(long long int i=4;i<=n;i++){
		dp[i]=dp[i-1]+dp[i-3];
	}printf("%lld",dp[n]);
}