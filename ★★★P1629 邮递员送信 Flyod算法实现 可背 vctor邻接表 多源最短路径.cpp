#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define INF 0x3f3f3f3f
#include<vector>
using namespace std;
//Flyod算法模板改(这题用Dijkstra更合适 仅为了测试Flyod) 正向为单源最短 回来是多源最短 
vector<vector<int>>cost;//代价矩阵 邻接表存储图 
//vector<vector<int>>path;//路径矩阵
//洛谷 c++11 o2优化 AC 
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
	//resize方法 v.resize(n) 将v的大小改成n v.resize(n,value) 将v的大小改成n 且元素为value 
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		//cost[a][b]=c;//单行路 
		cost[a][b]=min(cost[a][b],c);
	}
	for(int i=1;i<=n;i++) cost[i][i]=0; 
	Flyod();
	for(int i=2;i<=n;i++) ans=ans+cost[1][i]+cost[i][1];
	printf("%d",ans);
	return 0;
}

 
