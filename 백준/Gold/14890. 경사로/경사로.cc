#include<stdio.h>
int main(){
    int n;
    int a[201][201]={};
    int ch[201][201]={};
    int l;
    int count=0;
    scanf("%d %d",&n,&l);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int now=0;
    int p=1;//posible
    
    for(int i=0;i<n;i++){
        p=1;
        now=a[i][0];
        for(int j=1;j<n;j++){
            now=a[i][j-1];
            if(a[i][j]>now&&a[i][j]-now==1){
                //printf("(%d)",j);
                for(int k=1;k<=l;k++){
                    if(j-l-k>=0&&a[i][j-l-k]>now){
                        p=0;
                        //printf("@");
                        break;
                    }
                }
                if(p==0){
                    continue;
                }
                for(int k=1;k<=l;k++){
                    if(j-k<0){
                        //printf("!");
                        p=0;
                        break;
                    }
                    if(a[i][j-k]!=now){
                        p=0;
                        //printf("?");
                        break;
                    }
                }
            }
            else if(a[i][j]<now&&now-a[i][j]==1){
                //printf("(%d)",j);
                for(int k=0;k<l;k++){
                    if(j+k>=n){
                        //printf("$");
                        p=0;
                        break;
                    }
                    if(a[i][j+k]!=a[i][j]){
                        p=0;
                        //printf("#");
                        break;
                    }
                }
            }
            else if(a[i][j]==now){
                //printf("(%d)s",j);
            }
            else{
                //printf(".");
                p=0;
                break;
            }
        }
        //printf(" %d:%d\n",i,p);
        if(p==1){
            count++;
        }
        p=1;
        for(int j=1;j<n;j++){
            now=a[j-1][i];
            if(a[j][i]>now&&a[j][i]-now==1){
                //printf("(%d)",j);
                for(int k=1;k<=l;k++){
                    if(j-l-k>=0&&a[j-l-k][i]>now){
                        p=0;
                        //printf("@");
                        break;
                    }
                }
                if(p==0){
                    continue;
                }
                for(int k=1;k<=l;k++){
                    if(j-k<0){
                        //printf("!");
                        p=0;
                        break;
                    }
                    if(a[j-k][i]!=now){
                        p=0;
                        //printf("?");
                        break;
                    }
                }
            }
            else if(a[j][i]<now&&now-a[j][i]==1){
                //printf("(%d)",j);
                for(int k=0;k<l;k++){
                    if(j+k>=n){
                        //printf("$");
                        p=0;
                        break;
                    }
                    if(a[j+k][i]!=a[j][i]){
                        p=0;
                        //printf("#");
                        break;
                    }
                }
            }
            else if(a[j][i]==now){
                //printf("(%d)s",j);
            }
            else{
                //printf(".");
                p=0;
                break;
            }
        }
        //printf(" %d:%d\n",i,p);
        if(p==1){
            count++;
        }
    }
    
    printf("%d",count);
}