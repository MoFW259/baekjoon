#include <stdio.h>
int main(){
	int n,o;
	scanf("%d",&o);
	for(int i=1;i<=o;i++){
		scanf("%d",&n);
		if(n==1){
			printf("E\n");
		}else{
			printf("O\n");
		}
	}
}