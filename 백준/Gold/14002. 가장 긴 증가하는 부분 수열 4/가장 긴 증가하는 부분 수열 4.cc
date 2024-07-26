#include <stdio.h>
#include <algorithm>
using namespace std;
int a[1000001],notdp[1000001],track_notdp[1000001],n,arr[1000001];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}int r=0;
	for(int i=1;i<=n;i++){
		if(notdp[r-1]<a[i]||r==0){
			notdp[r]=a[i];
			track_notdp[i]=r;
			r++;
		} 
		else{
			int p=lower_bound(notdp,notdp+r,a[i])-notdp;
			notdp[p]=a[i];
			track_notdp[i]=p;
		}
		//printf("%d ",notdp[i]);
	}printf("%d\n",r);
	int rr=r;
	for(int i=n;i>=1;i--){
		if(track_notdp[i]==rr-1){
			arr[rr-1]=a[i];
			rr--;
		}
	}for(int i=0;i<r;i++){
		printf("%d ",arr[i]);
	}
}