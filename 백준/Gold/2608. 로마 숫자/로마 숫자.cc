#include <stdio.h>
#include <string.h>
char c[10000];int a=0;
int f(){
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='M'){
			a+=1000;
		}else if(c[i]=='D'){
			a+=500;
		}else if(c[i]=='C'){
			if(c[i+1]=='D'||c[i+1]=='M'){
				a-=100;
			}else{
				a+=100;
			}
		}else if(c[i]=='L'){
			a+=50;
		}else if(c[i]=='X'){
			if(c[i+1]=='L'||c[i+1]=='C'){
				a-=10;
			}else{
				a+=10;
			}
		}else if(c[i]=='V'){
			a+=5;
		}else{
			if(c[i+1]=='V'||c[i+1]=='X'){
				a--;
			}else{
				a++;
			}
		}
	}
	return a;
}
int main(){
	int b=0,n,o,count=0,p=1;
	for(int i=1;i<=2;i++){
		scanf("%s",&c);
		f();
	}
	printf("%d\n",a);
	for(int i=1;i<=10000;i*=10){
		if(a/i==0){
			break;
		}count++;
	}for(int i=1;i<=count-1;i++){
		p=p*10;
	}for(int i=count;i>=1;i--){
		int t=a/p;
		//printf("%d\n",p);
		if(i==4){
			for(int j=1;j<=t;j++){
				printf("M");
			}
		}else if(i==3){
			if(t==4){
				printf("CD");
			}else if(t==9){
				printf("CM");
			}else if(t>=5){
				printf("D");
				for(int j=1;j<=t-5;j++){
					printf("C");
				}
			}else{
				for(int j=1;j<=t;j++){
					printf("C");
				}
			}
		}else if(i==2){
			if(t==4){
				printf("XL");
			}else if(t==9){
				printf("XC");
			}else if(t>=5){
				printf("L");
				for(int j=1;j<=t-5;j++){
					printf("X");
				}
			}else{
				for(int j=1;j<=t;j++){
					printf("X");
				}
			}
		}else{
			if(t==4){
				printf("IV");
			}else if(t==9){
				printf("IX");
			}else if(t>=5){
				printf("V");
				for(int j=1;j<=t-5;j++){
					printf("I");
				}
			}else{
				for(int j=1;j<=t;j++){
					printf("I");
				}
			}
		}
		a=a%p;
		p/=10;
		
	}
}