#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;
	cin>>x;
	bool j1 =  x%2==0;
	bool j2 = x>4 && x<=12;  //c++±ê×¼´íÎóÐ´·¨ 4<x<=12 
	if(j1 && j2) cout<<"1 "; else cout<<"0 ";
	if(j1 || j2) cout<<"1 "; else cout<<"0 ";
	if((j1 && !j2) || (!j1 && j2)) cout<<"1 "; else cout<<"0 ";
	if(!j1 && !j2) cout<<"1 "; else cout<<"0 ";
	return 0;
}
