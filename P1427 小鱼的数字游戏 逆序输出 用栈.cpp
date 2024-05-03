#include<bits/stdc++.h>
#include<stack>
using namespace std;
int main(){
	//”√’ª µœ÷
	stack<int> a;
	while(1){
		int x;cin>>x;a.push(x);
		if(a.top()==0) break;
	}
	while(!a.empty()){
		int y = a.top();a.pop();
		if(y!= 0) cout<<y<<" "; 
	} 
	return 0;
}
