#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,t,s;
	cin>>m>>t>>s;
	if(t==0){
		cout<<0;
	}else if(s>=m*t){
		cout<<0;
	}else{
		int num = ceil(s/t);
		if(s%t!=0) num+=1;
		cout<<m-num; 
	}
	return 0;
}
