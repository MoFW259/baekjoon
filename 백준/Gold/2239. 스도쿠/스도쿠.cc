#include <stdio.h>
#include <stdlib.h>
int a[10][10]={0},b=0,c,d;
int check(int x,int y,int n){
	for(int i=1;i<=9;i++){
		if(a[i][y]==n) return 0;
		if(a[x][i]==n) return 0;
	}
	for(int i=(x-1)/3*3+1;i<=(x-1)/3*3+3;i++){
		for(int j=(y-1)/3*3+1;j<=(y-1)/3*3+3;j++){
			if(a[i][j]==n) return 0;
		}
	}return 1;
}
int f(int x,int y){
	if(x*y>=82){
		for(int i=1;i<=9;i++){
			for(int j=1;j<=9;j++){
				printf("%d",a[i][j]);
			}printf("\n");
		}
		exit(0);
	}
	if(x==10) return 0;
	if(y==10){
		f(x+1,1);
		return 0;
	}
	if(a[x][y]==0){
		for(int i=1;i<=9;i++){
			if(check(x,y,i)==1){
				a[x][y]=i;
				f(x,y+1);
				a[x][y]=0;
			}//printf("%d %d\n",x,y);
		}return 0;
	}f(x,y+1);
	return 0;
}
int main(){
	char ch[10];
	for(int i=1;i<=9;i++){
		scanf("%s",ch);
		for(int j=1;j<=9;j++){
			a[i][j]=ch[j-1]-'0';
		}
	}
	f(1,1);
}