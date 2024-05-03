#include<bits/stdc++.h>
using namespace std;
#define MAXV 1005
#define MAXE 100005
#define INF INT_MAX
//Prim算法标准题型  堆优化+链式前向星
struct node{
	int to;
	int weight;
	int next;
}edge[MAXE];
int head[MAXV];bool visited[MAXV];int x=1;int dist[MAXV];
int n,m;int ans=0;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
} 
struct priority{
	int id;
	int dists;
	friend bool operator < (priority a,priority b){
		return a.dists>b.dists;
	}
};
priority_queue<priority> q;
void init(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmp1,tmp2,tmp3;scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
		add(tmp1,tmp2,tmp3);
		add(tmp2,tmp1,tmp3);
	}
	fill(visited,visited+MAXV,0);
	fill(dist,dist+MAXV,INF);
}
void Prim(){
	dist[1]=0;
	q.push(priority{1,0});
	while(!q.empty()){
		priority temp = q.top();q.pop();int tmpid=temp.id;
		if(!visited[tmpid]){
			visited[tmpid]=1;ans+=dist[tmpid];
			for(int i=head[tmpid];i;i=edge[i].next){
				int targ = edge[i].to;
				dist[targ]=min(dist[targ],edge[i].weight);
				if(!visited[targ]) q.push(priority{targ,dist[targ]});	
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(visited[i]!=1){
			printf("-1");return;
		}
	printf("%d",ans);
	return;
}
int main(){
	init();
	Prim();
	return 0;
}






