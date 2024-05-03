#include<bits/stdc++.h>
using namespace std;
string res;
int main(){
	int mark=1;
	cin>>res;
	if(res=="0" || res=="-0"){
		cout<<0;return 0;
	}
	if(res[0]=='-'){
		cout<<res[0];
		for(int i=res.length()-1;i;i--){
			if(res[i]=='0' && mark==1) continue;
			mark=0;
			cout<<res[i];
		}
	}else{
		for(int i=res.length()-1;i>=0;i--){
			if(res[i]=='0' && mark==1) continue;
			mark=0;cout<<res[i];
		}
	}
	return 0;
}







