#include <stdio.h>
#include <string.h>
char c[10000];
void number(){
	int t=0;
	for(int i=0;i<strlen(c);i++){
		t++;
	}
	for(int i=0;i<strlen(c);i++){
		int a=c[i]-'0';
		//printf("%d\n",a);
		if(t==4){
			for(int j=1;j<=a;j++){
				printf("M");
			}
		}else if(t==3){
			if(a==9) printf("CM");
			else if(a>=5){
				printf("D");
				for(int j=1;j<=a-5;j++){
					printf("C");
				}
			}else if(a==4){
				printf("CD");
			}else{
				for(int j=1;j<=a;j++){
					printf("C");
				}
			}
		}else if(t==2){
			if(a==9) printf("XC");
			else if(a>=5){
				printf("L");
				for(int j=1;j<=a-5;j++){
					printf("X");
				}
			}else if(a==4){
				printf("XL");
			}else{
				for(int j=1;j<=a;j++){
					printf("X");
				}
			}
		}else{
			if(a==9) printf("IX");
			else if(a>=5){
				printf("V");
				for(int j=1;j<=a-5;j++){
					printf("I");
				}
			}else if(a==4){
				printf("IV");
			}else{
				for(int j=1;j<=a;j++){
					printf("I");
				}
			}
		}
		t--;
	}
}
void alphabet(){
	int a=0;
	for(int i=0;i<strlen(c);i++){
		if(c[i]=='M')	a+=1000;		
		else if(c[i]=='C'){
			if(c[i+1]=='M')	a+=900,i++;
			else if(c[i+1]=='D') a+=400,i++;
			else a+=100;
		}else if(c[i]=='D'){
			a+=500;
		}else if(c[i]=='X'){
			if(c[i+1]=='C')	a+=90,i++;
			else if(c[i+1]=='L') a+=40,i++;
			else a+=10;
		}else if(c[i]=='L'){
			a+=50;
		}else if(c[i]=='I'){
			if(c[i+1]=='X')	a+=9,i++;
			else if(c[i+1]=='V') a+=4,i++;
			else a+=1;
		}else a+=5;
	}printf("%d",a);
}
int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",&c);
		if(c[0]<='9'){
			number();
		}else{
			alphabet();
		}
		printf("\n");
	}
}