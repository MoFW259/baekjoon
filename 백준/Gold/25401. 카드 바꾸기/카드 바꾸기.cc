#include<stdio.h>

int main(){
    int n;
    int arr[501]={};
    int temp[501]={};
    
    int cnt=0;
    int min;
    int t;
    
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        temp[i]=arr[i];
    }
    
    cnt=0;
    
    for(int i=1;i<n;i++){
        t=arr[i]-arr[i-1];
        cnt=0;
        //printf("<%d>",t);
        for(int j=0;j<n;j++){
            temp[j]=arr[j];
        }
        if(t!=0){
            for(int j=0;j<n;j++){
                if(i>j&&i!=j&&i-1!=j){
                    if(temp[j]!=-(i-j)*t+arr[i]){
                        temp[j]=-(i-j)*t+arr[i];
                        cnt++;
                        //printf("[%d]",j);
                    }
                }
                else if(i<j){
                    if(temp[j]!=(j-i)*t+arr[i]){
                        temp[j]=(j-i)*t+arr[i];
                        cnt++;
                        //printf("[%d]",j);
                    }
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                if(temp[j]!=arr[i]){
                    temp[j]=arr[i];
                    cnt++;
                }
            }
        }
        
        if(i==1){
            min=cnt;
        }
        else if(min>cnt){
            min=cnt;
        }
        /*
        for(int j=0;j<n;j++){
            printf("%d ",temp[j]);
        }
        printf("(%d)\n",cnt);*/
    }
    printf("%d",min);
}