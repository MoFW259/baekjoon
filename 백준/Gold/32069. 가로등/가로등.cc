#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
long long int l;
long long int n,k,c=1,arr[510000],a,am1,fif=500000;
int main(){
	scanf("%lld %lld %lld",&l,&n,&k);
	for(long long int i=1;i<=n;i++){
		scanf("%lld",&a);
		arr[0]++;
		if(i==1){
			if(a+1<=fif){
				arr[a+1]--;
			}
			//미리 1제거, 바로 옆 가로등 방지 
		}
		else{
			long long int t=a-am1;
			arr[1]++;
			if(t%2==1&&t/2+1<=fif){
				arr[t/2+1]=arr[t/2+1]-2;
			}else{
				if(t/2<=fif){
					arr[t/2]--;
				}
				if(t/2+1<=fif){
					arr[t/2+1]--;
				}
			}
		}if(i==n){
			arr[1]++;
			if(l-a+1<=fif){
				arr[l-a+1]--;
			}
		}
		am1=a;
	}long long cnt=0,s=0;
	for(long long int i=0;;i++){
		s+=arr[i];
		for(long long int j=1;j<=s;j++){
			if(cnt>=k) return 0;
			printf("%d\n",i);
			cnt++;
		}
	}
}
