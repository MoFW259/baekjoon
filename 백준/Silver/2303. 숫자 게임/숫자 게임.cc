#include<stdio.h>

int main(){
    int n;
    int a[1001]={};
    int d[5]={};
    int t=0;
    int mi=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++){
            scanf("%d",&d[j]);
        }
        t=0;
        for(int j=0;j<5;j++){
            for(int k=j+1;k<5;k++){
                for(int l=k+1;l<5;l++){
                    t=(d[j]+d[k]+d[l])%10;
                    //printf("%d %d %d %d\n",d[j],d[k],d[l],t);
                    if(a[i]<t){
                        a[i]=t;
                    }
                }
            }
        }
        if(a[i]>=a[mi]){
            mi=i;
        }
    }
    printf("%d",mi);
}