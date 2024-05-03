#include<bits/stdc++.h>
using namespace std;
#define MAXV 20000
#define INF INT_MAX
//最小生成树 模板题  将输入的邻接矩阵转成链式前向星
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];int x=1;int dis[MAXV];
int visited[MAXV];int N;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	fill(dis,dis+MAXV,INF);
	fill(visited,visited+MAXV,0);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++){
			int tmp;scanf("%d",&tmp);
			if(i!=j) {
				add(i,j,tmp);add(j,i,tmp);
			}
		}
}
struct priority{
	int id;
	int dists;
	friend bool operator < (priority a,priority b){
		return a.dists>b.dists;
	}
};
priority_queue<priority> q;
void Prim(){
	dis[1]=0;q.push(priority{1,0});int ans=0;
	while(!q.empty()){
		priority tmp = q.top();q.pop();
		int tmpid = tmp.id;
		if(!visited[tmpid]){
			visited[tmpid]=1;ans+=dis[tmpid];
			for(int i=head[tmpid];i;i=edge[i].next){
				int v = edge[i].to;int w = edge[i].weight;
				if(dis[v]>w) dis[v]=w;
				if(!visited[v]) q.push(priority{v,dis[v]});
			}
		}
	}
	printf("%d",ans);
}
int main(){
	init();
	Prim();
	return 0;
}

 





