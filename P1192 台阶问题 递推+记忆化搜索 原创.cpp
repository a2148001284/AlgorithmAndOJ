#include<bits/stdc++.h>
using namespace std;
int n,k;int dp[100005];
#define mod 100003
//记忆化搜索+递归  可行 AC (原创)  最开始错是因为i=now 下标界限写错了 
int dfs1(int now){ //逆向 
	if(dp[now]!=0) return dp[now];
	if(now<k){
		for(int i=now-1;i>=0;i--) dp[now]=(dp[now]+dfs1(i))%mod;
		return dp[now]%mod;
	}
	if(now>=k){
		//正确写法: 
		for(int i=now-1;i>=now-k;i--) dp[now]=(dp[now]+dfs1(i))%mod;
		//for(int i=now;i>=now-k+1;i--) dp[now]=(dp[now]+dfs1(i-1))%mod;
		//错误写法:
		//dp[now]+=(dfs1(i-1)%mod);  报错WA 
		//return dp[now];  少%mod 报错TLE 
		//dp[now]+=dfs1(i-1); 报错WA 
		return dp[now]%mod;
	}
}
//我的想法的一个经过数学分析后的优化算法 (非原创) 
int dfs2(){ //另一个更简单的数学规律 AC 但是要注意可能会有负数 因为有减 
	for(int i=2;i<=n;i++){
		if(i<=k) dp[i]=(dp[i-1]*2)%mod;
		else dp[i]=(dp[i-1]*2-dp[i-k-1])%mod; //后面的dp取mod后可能比前面的小 做减法会有负数 
	}
	return (dp[n]+mod)%mod; //很关键 防止有负数 
} 
//来自网友的方法 合理分析 前进1->k步  AC
int dfs3(){
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(i>=j) dp[i]=(dp[i]+dp[i-j])%mod;
	return dp[n]%mod;
} 
int dfs4(){  //正向  AC 原创 
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;i++){
		if(i<k){
			int tmp=i-1;while(tmp>=0){
				dp[i]=(dp[i]+dp[tmp])%mod;tmp--;
			}
		}else{
			int tmp=i-1;while(tmp>=i-k){
				dp[i]=(dp[i]+dp[tmp])%mod;tmp--;
			}
		}
	}
	return dp[n]%mod;
}
int main(){
	scanf("%d %d",&n,&k);
	fill(dp,dp+100005,0);
	dp[0]=1;dp[1]=1;
	printf("%d",dfs1(n));
	//printf("%d",dfs2());
	//printf("%d",dfs3());
	//printf("%d",dfs4());
	return 0;
}









