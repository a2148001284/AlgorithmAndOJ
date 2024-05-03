#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
int dp[MAXV][MAXV];//dp[i][j] ����ǰi����Ʒ�������,��������Ϊjʱ �õ�������ֵ
bool visited[MAXV];//������i����Ʒ��û�б�ѡ��
int maxv=0;int maxw=0;//�洢װ����Ʒ�������� 

//ѧϰ�ο���https://blog.csdn.net/weixin_51339377/article/details/124115465
//https://www.bilibili.com/video/BV1pY4y1J7na/?spm_id_from=333.337.search-card.all.click&vd_source=88c5e55ec893ae095df8e5412f160f66 

void init(){
/**
5 10
2 2 6 5 4
6 3 5 4 6
==>װ�������Ϊ8 �ܼ�ֵΪ15 
**/
	fill(visited,visited+MAXV,0);
	cin>>n;cin>>Bag_Weight;
	for(int i=1;i<=n;i++) cin>>weight[i];
	for(int i=1;i<=n;i++) cin>>value[i];
}

void GetDp(){//��̬�滮��dp 
	//1.���ñ߽�����
	for(int i=0;i<=n;i++) dp[i][0]=0;
	for(int j=0;j<=Bag_Weight;j++) dp[0][j]=0;
	
	//2.����dp����
	for(int i=1;i<=n;i++)
		for(int j=1;j<=Bag_Weight;j++){
			if(weight[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		} 
}

void GetTarget(){
	//����ֵ����dp�����dp[n][Bag_Weight] 
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
		if(visited[i]) cout<<"��Ʒ"<<i<<" ����Ϊ:"<<weight[i]<<" ��ֵΪ:"<<value[i]<<"  ��ѡ����"<<endl; 
}

int main(){
	init();
	GetDp();
	GetTarget();
	DisChoose();
	cout<<"װ����Ʒ��������Ϊ:"<<maxw<<endl;
	cout<<"�ܼ�ֵΪ:"<<dp[n][Bag_Weight]<<endl; //��maxv��� 
	//cout<<maxv<<endl;
	return 0;
}


