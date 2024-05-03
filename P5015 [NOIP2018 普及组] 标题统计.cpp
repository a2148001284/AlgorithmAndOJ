#include<bits/stdc++.h>
using namespace std;
int main(){
	string res;int counts=0;getline(cin,res);
	for(int i=0;i<=res.length()-1;i++) if(res[i]!=' ') counts++;
	cout<<counts;
	return 0;
}









