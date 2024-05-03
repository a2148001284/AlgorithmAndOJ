#include<bits/stdc++.h>
using namespace std;
int a[1002][1002];
int visited[1002][1002];int n,m;
//可以用记忆化优化 因为输入的数据可能重复 可以采用记忆的方法 
//ans记录每一轮输入的对应的最优解
//visited记忆是否被访问 记忆化优化 使其记录本轮flag而不是0或1 后续可以直接找到其对应的轮次 避免多次计算 
int ans[100002];
void dfs(int x,int y,int flag){
	if(visited[x][y]!=-1 || x<1 || x>n || y<1 || y>n) return;
	visited[x][y]=flag;ans[flag]++;
	if(a[x+1][y]!=a[x][y]) dfs(x+1,y,flag);
	if(a[x-1][y]!=a[x][y]) dfs(x-1,y,flag);
	if(a[x][y+1]!=a[x][y]) dfs(x,y+1,flag);
	if(a[x][y-1]!=a[x][y]) dfs(x,y-1,flag);
}
int main(){
	scanf("%d%d",&n,&m);
	//一直各种错的原因如下: 例如 010101/10=416 0开头的数字被当成了八进制 
//	for(int i=1;i<=n;i++){
//		int targ;scanf("%d",&targ);
//		for(int j=n;j>=1;j--){
//			a[i][j]=targ%10;
//			targ/=10;
//		}
//	}
	//正确输入方法 单字符输入+拆分 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char ch;cin>>ch;a[i][j]=ch-'0';
		} 
	fill(ans,ans+100002,0);
	fill(visited[0],visited[0]+1002*1002,-1);//二维数组的赋值方式有[0] 
	for(int j=1;j<=m;j++){
		int tmp1,tmp2;scanf("%d %d",&tmp1,&tmp2);
		if(visited[tmp1][tmp2]==-1) dfs(tmp1,tmp2,j);
		else ans[j]=ans[visited[tmp1][tmp2]];  //记忆化搜索 核心避免TLE 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}



