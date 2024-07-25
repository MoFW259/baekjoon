#include <stdio.h>
int main(){
	int a,b,c,x=1;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d\n",a+b-c);
	for(int i=10;i<=10000;i*=10){
		if(b/i<1){
			x=i;
			break;
		}
	}
	printf("%d",a*x+b-c);
}