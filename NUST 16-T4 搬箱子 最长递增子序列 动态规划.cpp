#include<bits/stdc++.h>
#define MAXV 505
using namespace std;
int n,a[MAXV];int dp[MAXV];int ans;
void init(){
	cin>>n;for(int i=1;i<=n;i++) cin>>a[i];
	fill(dp,dp+n,1);
}
void Longest(){
	for(int i=2;i<=n;i++)
		for(int j=1;j<=i-1;j++){
			if(a[i]>a[j]) dp[i]=max(dp[i],dp[j]+1);
		}
	for(int i=1;i<=n;i++) ans=max(ans,dp[i]);
	cout<<ans<<endl;
}
int main(){
	init();
	Longest();
	return 0;
}




