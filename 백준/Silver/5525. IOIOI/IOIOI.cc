#include<stdio.h>

int main(){
    int n;
    int m;
    char str[10001];
    int c=0;
    int ch=0;
    scanf("%d %d",&n,&m);
    scanf("%s",&str[0]);
    for(int i=0;i<m;i++){
        if(str[i]=='\0'){
            break;
        }
        if(str[i]=='I'){
            ch=1;
            for(int j=0;j<n;j++){
                if(i+1+j*2+1>m){
                    ch=0;
                    break;
                }
                if(str[i+1+j*2]!='O'||str[i+1+j*2+1]!='I'){
                    ch=0;
                    break;
                }
            }
            c+=ch;
        }
    }
    printf("%d",c);
}