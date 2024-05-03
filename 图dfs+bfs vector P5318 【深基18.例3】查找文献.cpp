#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
#define MAXN 100010   //��󶥵��� 
vector<int> G[MAXN];  //vector���� �ڽӱ�ķ�ʽ��ͼ
bool visited[MAXN]={0};  //����dfs��bfs��visit����
queue<int> q; //bfs�õĶ���
int n,m; //nΪ�ڵ��� mΪ����

void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp1,temp2;cin>>temp1>>temp2;
		G[temp1].push_back(temp2);
	}
	
	//sort  �״�iӦ����1->n ������0��n-1 ��Ϊ���ʱ����С���ǵ�1 
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
	} 
} 

void dfs(int x){
	if(visited[x]) return;
	visited[x]=1;cout<<x<<" ";
	for(int i=0;i<G[x].size();i++) dfs(G[x][i]);
}

void bfs(int x){//�Ӷ���x��ʼ���ȱ��� 
	q.push(x);
	while(!q.empty()){
		int temp = q.front();q.pop();
		if(visited[temp]) continue;
		visited[temp]=1;cout<<temp<<" ";
		for(int i=0;i<G[temp].size();i++) q.push(G[temp][i]);
	}
}

int main(){
	init();
	dfs(1);cout<<endl;
	memset(visited,0,sizeof(visited));
	bfs(1);
	return 0;
}
