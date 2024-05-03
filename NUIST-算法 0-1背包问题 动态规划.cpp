#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
int dp[MAXV][MAXV];//dp[i][j] 考虑前i个物品的情况下,背包容量为j时 得到的最大价值
bool visited[MAXV];//表明第i个物品有没有被选择
int maxv=0;int maxw=0;//存储装入物品的总重量 

//学习参考：https://blog.csdn.net/weixin_51339377/article/details/124115465
//https://www.bilibili.com/video/BV1pY4y1J7na/?spm_id_from=333.337.search-card.all.click&vd_source=88c5e55ec893ae095df8e5412f160f66 

void init(){
/**
5 10
2 2 6 5 4
6 3 5 4 6
==>装入的总重为8 总价值为15 
**/
	fill(visited,visited+MAXV,0);
	cin>>n;cin>>Bag_Weight;
	for(int i=1;i<=n;i++) cin>>weight[i];
	for(int i=1;i<=n;i++) cin>>value[i];
}

void GetDp(){//动态规划求dp 
	//1.设置边界条件
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int j=0;j<=Bag_Weight;j++) dp[0][j]=0;
	
	//2.覆盖dp数组
	for(int i=1;i<=n;i++)
		for(int j=1;j<=Bag_Weight;j++){
			if(weight[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		} 
}

void GetTarget(){
	//最大价值就是dp数组的dp[n][Bag_Weight] 
	int i=n;int r = Bag_Weight;
	while(i>=0){
		if(dp[i][r]!=dp[i-1][r]){
			visited[i]=1;r=r-weight[i];
			maxw+=weight[i];maxv+=value[i];
		}
		i--; 
	}
}

void DisChoose(){
	for(int i=1;i<=n;i++)
		if(visited[i]) cout<<"物品"<<i<<" 重量为:"<<weight[i]<<" 价值为:"<<value[i]<<"  被选择了"<<endl; 
}

int main(){
	init();
	GetDp();
	GetTarget();
	DisChoose();
	cout<<"装入物品的总重量为:"<<maxw<<endl;
	cout<<"总价值为:"<<dp[n][Bag_Weight]<<endl; //和maxv相等 
	//cout<<maxv<<endl;
	return 0;
}


