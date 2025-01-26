#include<stdio.h>

int main(){
    int n;
    int d[100001]={};
    int b1;
    int b2;
    int g;
    int c=0;
    int max=0;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&d[i]);
    }
    //b1,b2,g
    for(int i=1;i<n-1;i++){
        c=0;
        //b2->i
        for(int j=i+1;j<n;j++){
            c+=d[j];
        }
        for(int j=1;j<n;j++){
            if(j!=i){
                c+=d[j];
            }
        }
        if(max<c){
            max=c;
        }
    }
    //b1,g,b2
    for(int i=1;i<n-1;i++){
        c=0;
        for(int j=1;j<=i;j++){
            c+=d[j];
        }
        for(int j=n-2;j>=i;j--){
            c+=d[j];
        }
        if(max<c){
            max=c;
        }
    }
    //g,b2,b1
    for(int i=n-2;i>=0;i--){
        c=0;
        //b2->i
        for(int j=i-1;j>=0;j--){
            c+=d[j];
        }
        for(int j=n-2;j>=0;j--){
            if(j!=i){
                c+=d[j];
            }
        }
        if(max<c){
            max=c;
        }
    }
    printf("%d",max);
}