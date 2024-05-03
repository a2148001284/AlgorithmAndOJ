#include<bits/stdc++.h>
using namespace std;
#define MAXV 1005
int a[MAXV],n;int dp[MAXV]; //dp[i]表示以a[i]结尾的子序列的长度 
int ans=0; int path[MAXV];//path用于记录上一个 从而存路线 
int counts=1;
void init(){
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i]; 
	fill(dp,dp+n,1); 
	fill(path,path+MAXV,0);
}
void Longest(){
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++)
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
void dfs(int start){
	if(path[start]==0){
		cout<<"第"<<counts<<"条路线是:";counts++;
		cout<<a[start]<<" ";
		return;
	}
	dfs(path[start]);
	//cout<<"start:"<<start<<endl;
	cout<<a[start]<<" "; 
}
//输入路径时发现路径并不唯一 但是ans是唯一的 
//由于是动态规划 dp的更新规则在等号处有些区别 dp不同 输出的路径并不全面 所以一般只能求ans 这个固定 
void Longest_Dispath(){
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i-1;j++)
//			if(a[i]>a[j] && dp[i]<dp[j]+1){
//				dp[i]=dp[j]+1;path[i]=j; 
//			}
			if(a[i]>=a[j] && dp[i]<=dp[j]+1){
				dp[i]=dp[j]+1;path[i]=j; 
			}
//			if(a[i]>=a[j] && dp[i]<dp[j]+1){
//				dp[i]=dp[j]+1;path[i]=j; 
//			}
//			if(a[i]>a[j] && dp[i]<=dp[j]+1){
//				dp[i]=dp[j]+1;path[i]=j; 
//			}
		ans=max(ans,dp[i]);
	}
	cout<<"最长子序列长度:"<<ans<<endl;
	for(int i=1;i<=n;i++){
		cout<<"dp["<<i<<"]:"<<dp[i]<<endl;
		if(dp[i]==ans){
			dfs(i);	cout<<endl;
		} 
	}
} 
int main(){
	init();//Longest();
	Longest_Dispath();
	return 0;
}















