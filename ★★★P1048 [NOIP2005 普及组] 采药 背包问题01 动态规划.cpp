#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
//01背包问题 dp动态规划
//dp[i][j] 考虑前i个物品的情况下,背包容量为j时 得到的最大价值
int T,M;int value[MAXN];int weight[MAXN];//T为可用重量 M为物品总数 
bool visited[MAXN];int dp[MAXN][1005];int maxv=0;//过不了洛谷的原因：dp数组的大小理解上 dp[i][j] 考虑i个物品，背包容量剩余j时的 最大价值 
int dp2[1005];
void init(){
	scanf("%d%d",&T,&M); 
	for(int i=1;i<=M;i++) scanf("%d%d",&weight[i],&value[i]);
}
void GetDp(){ //二维数组方式 
	for(int i=0;i<=M;i++) dp[i][0]=0;
	for(int j=0;j<=T;j++) dp[0][j]=0;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=T;j++){ 
			if(weight[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		}
}
void GetDp2(){ //优化dp 用一位数组+循环更新 减少空间的使用 
	//边界条件 无论如何i为任何值 背包容量为0的时候 价值都是0
	dp2[0]=0; 
	 for(int i=1;i<=M;i++)
	 //且j的范围不能是j>=1 因为j-weight[i]会变成负数 
	 	for(int j=T;j>=weight[i];j--){ //由于不是二维数组 dp2[j-weight[i]] 会先被更新 从而导致错误 所以要逆序更新 
		 	if(j<weight[i]) dp2[j]=dp2[j];//这句话多余 可以参考最新的二刷的那个cpp背诵 
		 	else dp2[j]=max(dp2[j],dp2[j-weight[i]]+value[i]);
		 }
	//最终结果存储在dp2[T] 默认是更新了i=M后 考虑了M个物品后 背包容量为T的情况后的最大价值 
	//但是丢失了选择的情况 要看情况请使用二维数组查看 
	
}
void GetChoose(){
	int n=M;int r=T;//n为个数 r为时间/重量 
	while(n>=0){
		if(dp[n][r]!=dp[n-1][r]){
			visited[n]=1;r=r-weight[n];maxv+=value[n];
		} 
		n--;
	}
}
int main(){
	init();
	//GetDp();
	//GetChoose();
	//printf("%d",dp[M][T]);
	GetDp2();
	printf("%d",dp2[T]);
	//printf("%d",maxv);
	return 0;
}

 




