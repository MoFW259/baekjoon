#include<stdio.h>

int main(){
    int n;
    int max=0;
    int mn;//max num
    int t1;
    int t2;
    int cnt=0;
    scanf("%d",&n);
    for(int i=0;i<=n;i++){
        cnt=3;
        t1=i;
        t2=n-i;
        //printf("%d %d ",t1,t2);
        while(t2>=0){
            t2=t1-t2;
            t1=t1-t2;
            //printf("%d ",t2);
            cnt++;
        }
        //printf(" (%d)\n",cnt);
        if(cnt>max){
            max=cnt;
            mn=i;
        }
        else if(cnt<max){
            break;
        }
    }
    t1=mn;
    t2=n-t1;
    printf("%d\n%d %d %d ",max-1,n,t1,t2);
    while(t2>=0){
        t2=t1-t2;
        t1=t1-t2;
        if(t2<0){
            break;
        }
        printf("%d ",t2);
    }
}