#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<string.h>
using namespace std;
#define MAXN 100010   //最大顶点数 
vector<int> G[MAXN];  //vector数组 邻接表的方式存图
bool visited[MAXN]={0};  //用于dfs和bfs的visit数组
queue<int> q; //bfs用的队列
int n,m; //n为节点数 m为边数

void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp1,temp2;cin>>temp1>>temp2;
		G[temp1].push_back(temp2);
	}
	
	//sort  易错：i应该是1->n 而不是0到n-1 因为存的时候最小都是点1 
	for(int i=1;i<=n;i++){
		sort(G[i].begin(),G[i].end());
	} 
} 

void dfs(int x){
	if(visited[x]) return;
	visited[x]=1;cout<<x<<" ";
	for(int i=0;i<G[x].size();i++) dfs(G[x][i]);
}

void bfs(int x){//从顶点x开始优先遍历 
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
