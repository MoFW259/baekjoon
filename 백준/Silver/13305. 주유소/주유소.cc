#include<stdio.h>

int main(){
    int n;
    long long int len[100001];
    long long int city[100001];
    
    long long int m=0;
    long long int now=0;
    
    scanf("%d",&n);
    for(int i=0;i<n-1;i++){
        scanf("%lld",&len[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%lld",&city[i]);
    }
    
    now=city[0];
    for(int i=1;i<n;i++){
        //printf("%lld %lld\n",now,m);
        m+=now*len[i-1];
        if(now>city[i]){
            now=city[i];
        }
    }
    printf("%lld",m);
}