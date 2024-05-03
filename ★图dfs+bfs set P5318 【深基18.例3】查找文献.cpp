#include<iostream>
#include<queue>
#include<set>
#include<string.h>
using namespace std;
int n,m;
queue<int> q;
#define MAXV 100010
bool visited[MAXV]={0};
set<int> G[MAXV];  //邻接表 
void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		int temp1,temp2;cin>>temp1>>temp2;
		G[temp1].insert(temp2);
	}
}

void dfs(int x){
	if(visited[x]) return;
	visited[x]=1;cout<<x<<" ";
	//for(int i=0;i<G[x].size();i++) dfs(G[x][i]);
	//set的访问需要使用迭代器才可以访问 直接被下面这种写法 
	for(int v:G[x]) dfs(v);//重要!!! 
}

void bfs(int x){
	q.push(x);
	while(!q.empty()){
		int x=q.front();q.pop();
		if(visited[x]) continue;
		visited[x]=1;cout<<x<<" ";
		for(int v:G[x]) q.push(v);
	}
} 

int main(){
	init();
	dfs(1);cout<<endl;
	memset(visited,0,sizeof(visited));
	bfs(1);
	return 0;
}

