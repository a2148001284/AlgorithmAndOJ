#include<bits/stdc++.h>
using namespace std;
char a[1002][1002];
int visited[1002][1002];int n,m;
//可以用记忆化优化 因为输入的数据可能重复 可以采用记忆的方法 
//ans记录每一轮输入的对应的最优解
//visited记忆是否被访问 记忆化优化 使其记录本轮flag而不是0或1 后续可以直接找到其对应的轮次 避免多次计算 
int ans[100002];
void dfs(int x,int y,int flag,int tag){
	if(visited[x][y]!=-1 || x<0 || x>=n || y<0 || y>=n || tag!=a[x][y]-'0') return;
	visited[x][y]=flag;ans[flag]++;
	dfs(x+1,y,flag,!tag);
	dfs(x-1,y,flag,!tag);
	dfs(x,y+1,flag,!tag);
	dfs(x,y-1,flag,!tag);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",a[i]);
	fill(visited[0],visited[0]+1002*1002,-1);
	for(int j=0;j<m;j++){
		int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);tmp1--;tmp2--;
		if(visited[tmp1][tmp2]==-1) dfs(tmp1,tmp2,j,a[tmp1][tmp2]-'0');
		else ans[j]=ans[visited[tmp1][tmp2]];  //记忆化搜索 核心避免TLE 
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<endl;
	return 0;
}





