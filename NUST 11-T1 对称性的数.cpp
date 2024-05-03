#include<bits/stdc++.h>
using namespace std;
void test(int x){
	int res = x*x;string ress = to_string(res);int i;
	for(i=0;i<=(ress.length()/2);i++){
		if(i<=(ress.length()-i-1) && ress[i] == ress[ress.length()-i-1]) continue;
		else break;
	} 
	if(i>(ress.length()/2)) cout<<x<<" ";
	else return;
}
int main(){
	int n;cin>>n;
	for(int i=1;i<n;i++) test(i);
	return 0;
}
