#include<bits/stdc++.h>
using namespace std;
int n,m;int weight[40];int left_num;int maxs=0; 
bool visited[40];//����ѡ�� ����ѡ�е����� 
//��dfsö����dp 
void GetDp(){
	//�����ѡ�������� �������ͻ�������ѡ�������ϳ����п��е����� 0-1��������ͳ�����տ��ܽ������ 
//	for(int i=1;i<=n;i++) if(visited[i]==1) cout<<i<<" ";
//	cout<<endl; 
	//��̬�滮dp ��ά����汾
	//dp[i][j] ��ǰѡȡ���˵�i������ ͨ��1->i������ ���Գ���������Ϊj ��Ϊtrue
	//״̬ת�Ʒ��̣� dp[i][j]=dp[i-1][j]||dp[i-1][j-weight[i]] 
	
	int weight_choose[left_num+1];int counts=0;int total_weight=0;
	for(int i=1;i<=n;i++) if(visited[i]==true) weight_choose[counts++]=weight[i],total_weight+=weight[i];
	bool dp[left_num+1][total_weight+1];
	//���ó�ʼ����
	for(int i=0;i<=left_num;i++) dp[i][0]=true;
	//��ʼdp 
	for(int i=1;i<=left_num;i++)
		for(int j=1;j<=total_weight;j++){
			if(j<weight_choose[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j]||dp[i-1][j-weight_choose[i]];
		}
	
}
void dfs(int choose,int id){//Ӧ��ͨ��dfsѡ�����·�� Ȼ����ȥ�����·���µ������Ƕ��� 
	//choose�����Ѿ�ѡ��ĸ��� id������ǰ���������
	if(id>n) return;
	if(choose==left_num){ //�����Ѿ�ѡ�� ���Կ�ʼ����Dp����� 
		GetDp();return;
	}
	visited[id+1]=1;dfs(choose+1,id+1);//ѡ��id+1������ 
	visited[id+1]=0;dfs(choose,id+1);//���� ��ѡ��id+1������ 
}
int main(){
	scanf("%d%d",&n,&m);left_num=n-m;
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	visited[1]=1;dfs(1,1);visited[1]=0;dfs(0,1);
	return 0;
}

