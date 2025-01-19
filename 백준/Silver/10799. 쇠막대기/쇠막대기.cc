#include<stdio.h>

int main(){
    char str[100002]={};
    int stick=0;
    int sum=0;
    scanf("%s",&str[0]);
    for(int i=0;i<100001;i++){
        if(str[i]=='\0'){
            break;
        }
        if(str[i]=='('&&str[i+1]==')'){
            sum+=stick;
            i++;
            //printf("l");
        }
        else if(str[i]=='('){
            stick++;
            //printf("+");
        }
        else if(str[i]==')'){
            stick--;
            sum++;
            //printf("-");
        }
    }
    printf("%d",sum);
}