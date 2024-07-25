#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <string.h>
#include <iostream>
using namespace std;
bool f(string x,string y){
	if(x.size()==y.size()){
		return x<y;
	}else{
		return x.size()<y.size();
	}
}
int main(){
	int n;
	string c;
	scanf("%d",&n);
	vector <string> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	sort(v.begin(),v.end(),f);
	v.erase(unique(v.begin(),v.end()),v.end());
	for(int i=0;i<v.size();i++){
		if(v[i]!=""){
			cout<<v[i]<<endl;
		}
	}
}