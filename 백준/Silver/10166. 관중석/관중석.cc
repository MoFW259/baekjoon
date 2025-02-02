#include<stdio.h>

int gy(int a,int b){
    int r=a%b;
    if(r==0){
        return b;
    }
    return gy(b,r);
}

int main(){
    int d1;
    int d2;
    int t;
    int c=0;
    scanf("%d %d",&d1,&d2);
    int arr[2001][2001]={};
    for(int i=d1;i<=d2;i++){
        for(int j=1;j<=i;j++){
            t=gy(i,j);
            arr[i/t][j/t]=1;
            //printf("%d %d, %d %d\n",i,j,i/t,j/t);
        }
    }
    for(int i=1;i<2001;i++){
        for(int j=1;j<2001;j++){
            if(arr[i][j]==1){
                c++;
            }
        }
    }
    printf("%d",c);
}