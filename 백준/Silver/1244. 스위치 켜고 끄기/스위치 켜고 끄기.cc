#include<stdio.h>

int main(){
    int n;
    int arr[101]={};
    int m;
    int g;
    int t;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&g,&t);
        if(g==1){
            for(int j=1;j<=n;j++){
                if(j%t==0){
                    arr[j]=(arr[j]+1)%2;
                }
            }
        }
        else{
            arr[t]=(arr[t]+1)%2;
            for(int j=1;j<=n;j++){
                if(t-j<=0||t+j>n){
                    break;
                }
                if(arr[t+j]!=arr[t-j]){
                    break;
                }
                arr[t+j]=(arr[t+j]+1)%2;
                arr[t-j]=(arr[t-j]+1)%2;
            }
        }
    }
    for(int i=1;i<=n;i++){
        if(i%20==1&&i!=1){
            printf("\n");
        }
        printf("%d ",arr[i]);
    }
}