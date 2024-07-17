#include <stdio.h>
#include <math.h>
int f(int n){
	if(n==1) return 0;
	for(int i=2;i<(int)sqrt(n)+1;i++){
		if(n%i==0&&n!=i) return 0;
	}return 1;
}
int main(){
	int n,a=1,c=0;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		a*=10;
	}
	for(int i=a;i<a*10;i++){
		c=0;
		if(i%2==0&&i!=2) continue;
		if(a!=1&&(i/a)%2==0&&(i/a)!=2||i/a==1){
			continue;
		}if(a>=11){
			int t=i%a;int aa=a/10;
		if(a>=11&&(t/aa)%2==0&&(t/aa)!=2){
			
			continue;
		}	
		}
		if(a>=100001){
		int t=i%(a/10);int aa=a/100;
			if(a>=101&&(t/aa)%2==0&&(t/aa)!=2||t/aa==1){
			continue;
		}
		}if(a>=1001){
		int t=i%(a/100);int aa=a/1000;
			if(a>=1001&&(t/aa)%2==0||(t/aa)%5==0){
			continue;
		}
		}if(a>=10001){
		int t=i%(a/1000);int aa=a/10000;
			if(a>=10001&&(t/aa)%2==0||(t/aa)%5==0){
			continue;
		}
		}if(a>=100001){
		int t=i%(a/10000);int aa=a/100000;
			if(a>=100001&&(t/aa)%2==0||(t/aa)%5==0){
			continue;
		}
		}if(a>=1000001){
		int t=i%(a/100000);int aa=a/1000000;
			if(a>=1000001&&(t/aa)%2==0||(t/aa)%5==0){
			continue;
		}
		}if(a>=10000001){
		int t=i%(a/1000000);int aa=a/10000000;
			if(a>=10000001&&(t/aa)%2==0||(t/aa)%5==0){
			continue;
		}
		}
		
		for(int j=1;j<=a;j*=10){
			if(f(i/j)==0){
				c=1;
				break;
			}
		}if(c==0){
			printf("%d\n",i);
		}
	}
}