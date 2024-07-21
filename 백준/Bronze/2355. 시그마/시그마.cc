#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	long long int a,b;
	scanf("%lld %lld",&a,&b);
	printf("%d",(a+b)*(max(a,b)-min(a,b)+1)/2);
}