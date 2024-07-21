#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
long long int l,n,k,a[300001]={999999999},c=1,arr[5000002];
int main(){
	scanf("%lld %lld %lld",&l,&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	if(n==1&&l>5000000){
		int left=a[1]-1,right=a[1]+1,le=1,ri=1,cnt=1;
		printf("0\n");
		for(int i=1;i<=k;i++){
			if(cnt==k) return 0; 
			if(left>=0){
				printf("%d\n",le);
				left--;
				le++;
				cnt++;
			}
			if(cnt==k) return 0; 
			else if(right<=l){
				printf("%d\n",ri);
				right--;
				ri++;
				cnt++;
			}
		}
		return 0;
	}
	for(int i=0;i<=l;i++){
		if(i==a[c]){
			arr[i]=0;
			c++;
		}else{
			arr[i]=1;
		}
	}c=1;
	for(int i=0;i<=l;i++){
		if(i==a[c]){
			//printf("%d\n",i);
			c++;
			continue;
		}else{
			arr[i]=min(abs(i-a[c]),abs(i-a[c-1]));
		}
	}
	sort(arr,arr+l+1);
	for(int i=0;i<k;i++){
		printf("%lld\n",arr[i]);
	}
}
