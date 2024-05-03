#include<bits/stdc++.h>
using namespace std;
int n,m;int weight[40];int left_num;int maxs=0; 
bool visited[40];//根据选项 表明选中的砝码 
//先dfs枚举再dp 
void GetDp(){
	//砝码的选择测试完毕 接下来就基于这种选择进行组合出所有可行的重量 0-1背包问题统计最终可能结果数量 
//	for(int i=1;i<=n;i++) if(visited[i]==1) cout<<i<<" ";
//	cout<<endl; 
	//动态规划dp 二维数组版本
	//dp[i][j] 当前选取到了第i个砝码 通过1->i个砝码 可以称量出重量为j 则为true
	//状态转移方程： dp[i][j]=dp[i-1][j]||dp[i-1][j-weight[i]] 
	
	int weight_choose[left_num+1];int counts=0;int total_weight=0;
	for(int i=1;i<=n;i++) if(visited[i]==true) weight_choose[counts++]=weight[i],total_weight+=weight[i];
	bool dp[left_num+1][total_weight+1];
	//设置初始条件
	for(int i=0;i<=left_num;i++) dp[i][0]=true;
	//开始dp 
	for(int i=1;i<=left_num;i++)
		for(int j=1;j<=total_weight;j++){
			if(j<weight_choose[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]||dp[i-1][j-weight_choose[i]];
		}
	
}
void dfs(int choose,int id){//应该通过dfs选砝码的路径 然后在去算这个路径下的重量是多少 
	//choose表明已经选择的个数 id表明当前处理的砝码
	if(id>n) return;
	if(choose==left_num){ //砝码已经选好 可以开始进入Dp算情况 
		GetDp();return;
	}
	visited[id+1]=1;dfs(choose+1,id+1);//选择id+1的砝码 
	visited[id+1]=0;dfs(choose,id+1);//回溯 不选择id+1的砝码 
}
int main(){
	scanf("%d%d",&n,&m);left_num=n-m;
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	visited[1]=1;dfs(1,1);visited[1]=0;dfs(0,1);
	return 0;
}

