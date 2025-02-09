#include<stdio.h>
/*
5
2 1 6 9 10
->2
*/
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
        for(int k=1;k<n;k++){
            t=arr[i]-arr[i-k];
            cnt=0;
            //printf("<%d>",t);
            for(int j=0;j<n;j++){
                temp[j]=arr[j];
            }
            if(t!=0){
                for(int j=0;j<n;j++){
                    if(i!=1&&min<cnt){
                        break;
                    }
                    if(i>j&&i!=j&&i-n!=j){
                        if(temp[j]!=-(i-j)*(t/k)+arr[i]){
                            temp[j]=-(i-j)*(t/k)+arr[i];
                            cnt++;
                            //printf("[%d]",j);
                        }
                    }
                    else if(i<j){
                        if(temp[j]!=(j-i)*(t/k)+arr[i]){
                            temp[j]=(j-i)*(t/k)+arr[i];
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
        
    }
    printf("%d",min);
}