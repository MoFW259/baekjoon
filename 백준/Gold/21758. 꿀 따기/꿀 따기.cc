#include<stdio.h>

int main(){
    int n;
    int a[100001]={};
    int d[100001]={};
    int c=0;
    int max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    //printf("%d ",d[0]);
    d[0]=a[0];
    for(int i=1;i<n;i++){
        d[i]+=d[i-1]+a[i];
        //printf("%d ",d[i]);
    }
    //printf("\n");
    for(int i=1;i<n-1;i++){
        c=d[n-1]-a[0]+d[n-1]-d[i]-a[i];
        if(c>max){
            max=c;
        }
        c=d[n-2]+d[i-1]-a[i];
        if(c>max){
            max=c;
        }
        c=d[i]-a[0]+d[n-2]-d[i-1];
        if(c>max){
            max=c;
        }
    }
    printf("%d",max);
}