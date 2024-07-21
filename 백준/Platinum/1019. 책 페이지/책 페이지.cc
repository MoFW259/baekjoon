#include <stdio.h>
int main(){
	long long int n,arr[11]={},c=0,cc=1;
	scanf("%lld",&n);
	for(long long int i=10;i<=10000000000;i*=10){
		if(n/i==0){
			c=i/10;
			break;
		}
		cc++;
	}//1000 4
	//printf("%d %d",c,cc);
	long long int nn=n;
	long long int ccc=c;
	for(long long int i=cc;i>=1;i--){
		//printf("%lld\n",n);
		if(i==1){
			if(i==cc){
				for(long long int j=1;j<=n;j++){
					arr[j]+=1;
				}
				break;
			}
			for(long long int j=1;j<=9;j++){
				arr[j]+=1;
				
			}
			for(int j=0;j<=9;j++){
				arr[j]+=(nn/10-1);
			}for(int j=0;j<=n;j++){
				arr[j]+=1;
			}
		}else if(i==cc){
			for(long long int j=1;j<=n/c-1;j++){
				arr[j]+=c;
			}
			arr[n/c]+=(n%c+1);
		}else{//c=100,10
			for(int j=1;j<=9;j++){
				arr[j]+=c;
			}
			for(int j=0;j<=9;j++){
				arr[j]+=((nn/ccc-1)*c);
				//printf("%d %d %d\n",nn,ccc,c);
			}
			for(long long int j=0;j<=n/c-1;j++){
				arr[j]+=c;
			}
			arr[n/c]+=(n%c+1);
			ccc/=10;
		}
		n%=c;
		c/=10;
	}for(int i=0;i<=9;i++){
		printf("%d ",arr[i]);
	}
}