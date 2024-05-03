#include<bits/stdc++.h>
using namespace std;
#define MAXN 20
int n;
long long dp[MAXN][MAXN];//1:队列里还有几个待排序的数 2:栈里有几个数  dp记录当前状态下有几种情况 
long long dfs(int x,int y){
	if(dp[x][y]) return dp[x][y];
	if(x==0) return 1;
	if(y>0) dp[x][y]+=dfs(x,y-1);
	dp[x][y]+=dfs(x-1,y+1);
	return dp[x][y];
}

int main(){
	cin>>n;cout<<dfs(n,0);
	return 0;
}
