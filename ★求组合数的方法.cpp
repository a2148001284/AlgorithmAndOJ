#include<bits/stdc++.h>
#define MAXN 100
using namespace std;
long long DiGui(int n,int m){
	if(m==0 || m==n) return 1;
	return DiGui(n-1,m-1)+DiGui(n-1,m);
}

int dp[MAXN];
long long DiGuiDpOpt(int n,int m){
	if(m==0 || m==n) return 1;
	if(dp[n]!=0) return dp[n];
	else{
		dp[n] = DiGui(n-1,m-1)+DiGui(n-1,m);
		return dp[n];
	}
}
long long DieDai(int n,int m){  //±ß³Ë±ß³ý 
	long long res = 1;
	m = min(m,n-m);
	for(int i=0;i<m;i++){
		res*=(n-i);
		res/=(i+1);
	}
	return res;
}
int main(){
	int n,m;
	cin>>n>>m;
	//cout<<DiGui(n,m);  //10 5  1.407s
	//cout<<DiGuiDpOpt(n,m);  //10 5  1.72s
	//cout<<DieDai(n,m);  //10 5 1.092s
	return 0;
}




