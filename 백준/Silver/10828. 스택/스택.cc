#include <stdio.h>
#include <stack>
#include <queue>
using namespace std;
int main(){
	int n,a;
	char c[10];
	stack <int> s; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",c);
		if(c[0]=='p'){
			if(c[1]=='u'){
				scanf("%d",&a);
				s.push(a);
			}else{
				if(s.empty()){
					printf("-1\n");
				}else{
					int x=s.top();
					s.pop();
					printf("%d\n",x);
				}
			}
		}else if(c[0]=='t'){
			if(s.empty()){
				printf("-1\n");
			}else{
				printf("%d\n",s.top());
			}
		}else if(c[0]=='s'){
			printf("%d\n",s.size());
		}else{
			printf("%d\n",s.empty());
		}
	}
}