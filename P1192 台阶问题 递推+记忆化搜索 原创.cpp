#include<bits/stdc++.h>
using namespace std;
int n,k;int dp[100005];
#define mod 100003
//���仯����+�ݹ�  ���� AC (ԭ��)  �ʼ������Ϊi=now �±����д���� 
int dfs1(int now){ //���� 
	if(dp[now]!=0) return dp[now];
	if(now<k){
		for(int i=now-1;i>=0;i--) dp[now]=(dp[now]+dfs1(i))%mod;
		return dp[now]%mod;
	}
	if(now>=k){
		//��ȷд��: 
		for(int i=now-1;i>=now-k;i--) dp[now]=(dp[now]+dfs1(i))%mod;
		//for(int i=now;i>=now-k+1;i--) dp[now]=(dp[now]+dfs1(i-1))%mod;
		//����д��:
		//dp[now]+=(dfs1(i-1)%mod);  ����WA 
		//return dp[now];  ��%mod ����TLE 
		//dp[now]+=dfs1(i-1); ����WA 
		return dp[now]%mod;
	}
}
//�ҵ��뷨��һ��������ѧ��������Ż��㷨 (��ԭ��) 
int dfs2(){ //��һ�����򵥵���ѧ���� AC ����Ҫע����ܻ��и��� ��Ϊ�м� 
	for(int i=2;i<=n;i++){
		if(i<=k) dp[i]=(dp[i-1]*2)%mod;
		else dp[i]=(dp[i-1]*2-dp[i-k-1])%mod; //�����dpȡmod����ܱ�ǰ���С ���������и��� 
	}
	return (dp[n]+mod)%mod; //�ܹؼ� ��ֹ�и��� 
} 
//�������ѵķ��� ������� ǰ��1->k��  AC
int dfs3(){
	dp[0]=1;dp[1]=1;
	for(int i=2;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(i>=j) dp[i]=(dp[i]+dp[i-j])%mod;
	return dp[n]%mod;
} 
int dfs4(){  //����  AC ԭ�� 
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









