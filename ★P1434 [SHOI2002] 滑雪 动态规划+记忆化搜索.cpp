#include<bits/stdc++.h>
using namespace std;
#define MAXV 105
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int n,m;int a[MAXV][MAXV],s[MAXV][MAXV];int ans=0;
//s[i][j]表示i,j出发能走的最长距离 
int dfs(int x,int y){ //从(x,y)这个点出发 
	if(s[x][y]) return s[x][y];//记忆化搜索
	s[x][y]=1;
	for(int i=0;i<4;i++){
		int xx = dx[i]+x;
		int yy = dy[i]+y;
		if(xx>0 && xx<=n && yy>0 && yy<=m && a[x][y]>a[xx][yy])
			s[x][y]=max(s[x][y],dfs(xx,yy)+1);
	}
	return s[x][y];
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) cin>>a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans = max(ans,dfs(i,j));
	printf("%d",ans);
	return 0;
}



