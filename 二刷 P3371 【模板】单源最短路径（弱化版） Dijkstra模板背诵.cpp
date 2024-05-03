#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define MAXN 20005
#define MAXV 1000005
#define INF 0x3f3f3f3f
#include<queue>
using namespace std;
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];int head[MAXN];int x=1;bool visited[MAXN];int dis[MAXN];
int n,m,s; 
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		add(a,b,c);
	}
	fill(visited,visited+MAXN,0);
	fill(dis,dis+MAXN,INF);
}
struct priority{
	int id;int dist;
	friend bool operator < (priority a,priority b){
		return a.dist>b.dist;//小堆 
	}
};
priority_queue<priority> q;
void Dijkstra(){
	dis[s]=0;q.push(priority{s,dis[s]});
	while(!q.empty()){
		priority tmp=q.top();q.pop();int tmpid=tmp.id;
		if(!visited[tmpid]){
			visited[tmpid]=1;
			for(int i=head[tmpid];i;i=edge[i].next){
				int targ=edge[i].to;
				if(dis[targ]>dis[tmpid]+edge[i].weight){
					dis[targ]=dis[tmpid]+edge[i].weight;
					if(!visited[targ]) q.push(priority{targ,dis[targ]});
				}
			}
		}
	}
}
int main(){
	init();
	Dijkstra();
	for(int i=1;i<=n;i++){
		if(dis[i]!=INF) printf("%d ",dis[i]);
		else cout<<0x7fffffff<<" ";//有符号数 32比特 占用31比特为数值 则最大为2的31次方-1为最大数值 0111111111111111 
	} 
	return 0;
}


