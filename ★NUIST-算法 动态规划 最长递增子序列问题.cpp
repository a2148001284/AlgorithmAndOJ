#include<bits/stdc++.h>
using namespace std;
#define MAXV 1005
int a[MAXV],n;int dp[MAXV]; //dp[i]��ʾ��a[i]��β�������еĳ��� 
int ans=0; int path[MAXV];//path���ڼ�¼��һ�� �Ӷ���·�� 
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
		cout<<"��"<<counts<<"��·����:";counts++;
		cout<<a[start]<<" ";
		return;
	}
	dfs(path[start]);
	//cout<<"start:"<<start<<endl;
	cout<<a[start]<<" "; 
}
//����·��ʱ����·������Ψһ ����ans��Ψһ�� 
//�����Ƕ�̬�滮 dp�ĸ��¹����ڵȺŴ���Щ���� dp��ͬ �����·������ȫ�� ����һ��ֻ����ans ����̶� 
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
	cout<<"������г���:"<<ans<<endl;
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















