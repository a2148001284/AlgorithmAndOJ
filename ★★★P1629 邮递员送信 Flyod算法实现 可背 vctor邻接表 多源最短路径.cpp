#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#include<vector>
using namespace std;
//Flyod�㷨ģ���(������Dijkstra������ ��Ϊ�˲���Flyod) ����Ϊ��Դ��� �����Ƕ�Դ��� 
vector<vector<int>>cost;//���۾��� �ڽӱ�洢ͼ 
//vector<vector<int>>path;//·������
//��� c++11 o2�Ż� AC 
int n,m,ans=0;
void Flyod(){
	for(int k=1;k<=n;k++)
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++){
		if(cost[i][k]!=INF&&cost[k][j]!=INF&&cost[i][j]>cost[i][k]+cost[k][j]){
			cost[i][j]=cost[i][k]+cost[k][j];
			//path[i][j]=k;
		}
	}
}
int main(){
	scanf("%d%d",&n,&m);
	cost.resize(n+1,vector<int>(n+1,INF)); 
	//resize���� v.resize(n) ��v�Ĵ�С�ĳ�n v.resize(n,value) ��v�Ĵ�С�ĳ�n ��Ԫ��Ϊvalue 
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		//cost[a][b]=c;//����· 
		cost[a][b]=min(cost[a][b],c);
	}
	for(int i=1;i<=n;i++) cost[i][i]=0; 
	Flyod();
	for(int i=2;i<=n;i++) ans=ans+cost[1][i]+cost[i][1];
	printf("%d",ans);
	return 0;
}

 
