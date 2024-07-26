#include <stdio.h>
#include <algorithm>
using namespace std;
int n,dp[1000001],a=0;
void graph(int x){
	if(x==1){
		return;
	}
	int a=x-1;
	if(dp[a]>dp[x/2]&&x%2==0){
		a=x/2;
	}if(dp[a]>dp[x/3]&&x%3==0){
		a=x/3;
	}printf("%d ",a);
	graph(a);
}
int main(){
	scanf("%d",&n); 
	dp[1]=0;
	for(int i=2;i<=n;i++){
		dp[i]=dp[i-1]+1;
		if(i%2==0){
			dp[i]=min(dp[i],dp[i/2]+1);
		}if(i%3==0){
			dp[i]=min(dp[i],dp[i/3]+1);
		}
		
	}if(n==1){
		printf("0\n1");
		return 0;
	}
	printf("%d\n",dp[n]);
	if(n!=1) printf("%d ",n);
	graph(n);
}