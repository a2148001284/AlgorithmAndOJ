#include<bits/stdc++.h>
#define MAXN 404
using namespace std;
int n,m,x,y;
int dp[MAXN][MAXN];
void dfs(int dis,int x0,int y0){
	if(x0>n || y0>m || x0<=0 || y0 <=0 || (dp[x0][y0]>=0 && dp[x0][y0]<dis)) return;
	dp[x0][y0]=dis;//dp[x0][y0]<0
	dfs(dis+1,x0+1,y0-2);dfs(dis+1,x0+2,y0-1);
	dfs(dis+1,x0+2,y0+1);dfs(dis+1,x0+1,y0+2);
	dfs(dis+1,x0-1,y0+2);dfs(dis+1,x0-2,y0+1);
	dfs(dis+1,x0-2,y0-1);dfs(dis+1,x0-1,y0-2);
}
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
}
int main(){
	fill(dp[0],dp[0]+MAXN*MAXN,-1);
	scanf("%d%d%d%d",&n,&m,&x,&y);dp[x][y]=0;
	dfs(0,x,y);
	print();
	return 0;
}
