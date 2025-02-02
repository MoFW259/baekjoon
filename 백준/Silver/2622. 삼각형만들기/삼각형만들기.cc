#include<stdio.h>
#include<string.h>
int min(int a,int b){
    if(a<b){
        return a;
    }
    return b;
}
int main(){
    int n;
    int cnt=0;
    int k;
    scanf("%d",&n);
    for(int i=n-2;i>=1;i--){
        for(int j=min(n-i,i);j>0;j--){
            k=n-i-j;
            if(k<=0){
                continue;
            }
            if(k>j){
                continue;
            }
            if(k>i){
                continue;
            }
            if(j>i){
                continue;
            }
            if(i<k+j){
                //printf("%d %d %d\n",i,j,k);
                cnt++;
            }
            
        }
    }
    printf("%d",cnt);
}