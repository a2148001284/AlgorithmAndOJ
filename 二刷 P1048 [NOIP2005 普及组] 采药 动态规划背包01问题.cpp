#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MAXN 1005
using namespace std;
//01��������ģ��
int T,M;int times[MAXN];int values[MAXN];
int dp[MAXN][MAXN];//dp[i][j] ����ǰi����Ʒ,ʱ������Ϊjʱ ����ֵ 
//bool visited[MAXN];int maxvalue=0;
int dp2[MAXN];
void init(){
	scanf("%d%d",&T,&M);
	for(int i=1;i<=M;i++) scanf("%d%d",&times[i],&values[i]);
	for(int i=0;i<=T;i++) dp[0][i]=0;
	for(int i=0;i<=M;i++) dp[i][0]=0; 
	//fill(visited,visited+MAXN,0);
} 
void GetDp2(){ //����Ҫ��¼ѡ���ʱ�� ����ֱ����һά�����ʾ��������T ��Ʒ����M��ѭ����� ���ٿռ临�Ӷ�
 	dp2[0]=0;
	for(int i=1;i<=M;i++)
		for(int j=T;j>=0;j--){
			if(times[i]>j) dp2[j]=dp2[j];
			else dp2[j]=max(dp2[j],dp2[j-times[i]]+values[i]); 
		} 	
}
void GetDp(){
	for(int i=1;i<=M;i++)
		for(int j=1;j<=T;j++){
			if(j<times[i]) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-times[i]]+values[i]);
		}
}
int main(){
	init();//GetDp();
	GetDp2();
	//int tmp=M;int bagleft=T;
//	while(M>=0){//���ѡ��ķ��� ���ֻҪ��� �Ͳ���Ҫvisited��������� 
//		if(dp[M][bagleft]!=dp[M-1][bagleft]){
//			visited[M]=1;maxvalue+=times[M];
//			bagleft-=times[M];
//		}
//		M--; 
//	}
	//printf("%d",maxvalue);
	//printf("%d",dp[M][T]);
	printf("%d",dp2[T]);
	return 0;
}


