#include<stdio.h>

int main(){
    int n;
    int v[500001]={};
    long long int sum=0;
    long long int nv=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&v[i]);
    }
    v[n]=0;
    nv=v[n];
    for(int i=n-1;i>=0;i--){
        if(nv+1<=v[i]){
            nv+=1;
        }
        else{
            nv=v[i];
        }
        //printf("%lld ",nv);
        sum+=nv;
        //printf("%lld %d\n",nv,v[i]);
    }
    printf("%lld",sum);
}