#include<bits/stdc++.h>
#define MAXV 1000
using namespace std;
string target;int res=0;int n;
//1725102
void dfs(int start){
	//cout<<" target:"<<target[start];
	if(target[start]=='0') return;
	if(start==n-1){
		res++;return;
	} 
	dfs(start+1);
	char x1 = target[start];char x2=target[start+1];
	string xx1;xx1=x1;string xx2;xx2=x2;string sss = xx1+xx2;
	if(sss>="1" && sss<="26"){
		dfs(start+2);
	}
}
int main(){
	cin>>target;
	n=target.length();
	//×Ö·û´®charµÄÆ´½ÓµÄ³¢ÊÔ£¡£¡£¡ 
//	char a = target[1];
//	char b = target[2];
//	string aa;aa=a;string bb;bb=b;
//	cout<<aa+bb<<endl;
	dfs(0);
	cout<<res<<endl;
	return 0;
} 
