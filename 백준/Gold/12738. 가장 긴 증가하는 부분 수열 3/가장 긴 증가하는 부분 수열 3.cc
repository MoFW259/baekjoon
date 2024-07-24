#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000001],notdp[1000001],n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}int t=0,r=1,b=0,bb=0;
	notdp[1]=a[1];
	for(int i=2;i<=n;i++){
		if(notdp[r]<a[i]){
			r++;
			notdp[r]=a[i];
		} 
		else{
			notdp[lower_bound(notdp+1,notdp+1+r,a[i])-notdp]=a[i];
		}
	}printf("%d",r);
}