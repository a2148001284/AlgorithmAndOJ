#include<bits/stdc++.h>
using namespace std;
void Option(){
	stack<char> s;
	string target;cin>>target;
	for(int i=0;i<target.length();i++){
		if(target[i]=='(' || target[i]=='[' || target[i]=='{' || target[i]=='<')
			s.push(target[i]);
		else{
			char b = s.top();
			if( b=='('&&target[i]==')' || b=='['&&target[i]==']' || b=='{'&&target[i]=='}' || b=='<'&&target[i]=='>' ){
				s.pop();continue;		
			}else{
				cout<<"No"<<endl;return;
			}
		}
	}
	if(!s.empty()) cout<<"No"<<endl;
	else cout<<"Yes"<<endl;
}
int main(){
	for(int t=0;t<6;t++) Option();
	return 0;
}
