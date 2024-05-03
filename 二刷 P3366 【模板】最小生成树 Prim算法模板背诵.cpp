#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
//Prim最小生成树模板题
#define MAXN 5005
#define MAXV 400005 
#define INF 0x7fffffff
using namespace std;
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];int x=1;int head[MAXN];int n,m;
int dis[MAXN];bool visited[MAXN];int ans=0;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);add(b,a,c);//无向图构建 
	}
	fill(visited,visited+MAXN,0);fill(dis,dis+MAXN,INF);
} 
struct priority{
	int id;int dist;
	friend bool operator < (priority a,priority b){
		return a.dist>b.dist;//小堆 
	}
};
priority_queue<priority> q;
void Prim(){
	dis[1]=0;q.push(priority{1,dis[1]});
	while(!q.empty()){
		priority tmp = q.top();q.pop();int tmpid=tmp.id;
		if(!visited[tmpid]){
			visited[tmpid]=1;ans+=dis[tmpid];
			for(int i=head[tmpid];i;i=edge[i].next){
				int targ=edge[i].to;int w = edge[i].weight;
				dis[targ]=min(dis[targ],w);
				if(!visited[targ]) q.push(priority{targ,dis[targ]});
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!visited[i]){
			printf("orz");return;
		}
	printf("%d",ans);
}
int main(){
	init();
	Prim();
	return 0;
}
