#include<bits/stdc++.h>
using namespace std;
//经过道路的拥挤度最大值最小
//方法2:Dijkstra+堆优化+链式前向星 变种 
//贪心策略:dis数组存储到每个节点的最大拥挤度 用小根堆来每次选最大拥挤度最小的进行拓展即可(类比Prim算法)
//任意一个点 其最大拥挤度的最小值是与其相连的点的该值与边值取的max值 在所有max中取最小  
int n,m,s,t;
#define MAXN 30005  //多开点 可能就不够用 
#define INF 0x3f3f3f3f
struct node{
	int to;int weight;int next;
}edge[MAXN];bool visited[MAXN];int head[MAXN];int x=1;int dis[MAXN];//用来存储到节点的最大拥挤度 
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
struct priority{
	int id;
	int dist;
	friend bool operator <(priority a,priority b){//默认为大根堆 相反为小根堆 
		return a.dist>b.dist;
	}
};
priority_queue<priority> q;
void Dijkstra(){
	q.push(priority{s,0});
	while(!q.empty()){
		priority tmp = q.top();q.pop();int tmpId=tmp.id;
		if(visited[tmpId]) continue; visited[tmpId]=1;
		for(int i=head[tmpId];i;i=edge[i].next){
			int targ = edge[i].to;int maxs=max(dis[tmpId],edge[i].weight);//当前边tmpId->targ之间的 targ的最大拥挤度为maxs 
			if(maxs<dis[targ]) dis[targ]=maxs;//在所有和targ相关的情况中 取最小值 即所有最大拥挤度中取最小的 
			if(!visited[targ]) q.push(priority{targ,dis[targ]});
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);add(a,b,c);add(b,a,c);
	}
	fill(visited,visited+MAXN,0);
	fill(dis,dis+MAXN,INF);dis[s]=0;
	Dijkstra();printf("%d",dis[t]);
	return 0;
}









