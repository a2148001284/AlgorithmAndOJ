#include<bits/stdc++.h>
using namespace std;
//���⣺�������������г���������һ����ȡ�ķ��õ���Сֵ�Ƕ���
//������п��ܵ�·�ߵ��У�ÿ��·�߶�Ӧ�ĵ������õ�max���ٰ���Щmax���Ƚ�ȡ��min
#define INF INT_MAX
#define MAXN 10005
#define MAXV 100005  //�����ܹؼ� 
int n,m,b;
struct node{
	int to,weight,next;
}edge[MAXV];
int head[MAXN];int x=1;long long f[MAXN];long long high,low=INF,mid;
bool visited[MAXN];long long dist[MAXN];
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
struct priority{
	int id;
	long long dists;
	friend bool operator <(priority a,priority b){
		return a.dists>b.dists;
	}
};
void init(){
	scanf("%d%d%d",&n,&m,&b);
	for(int i=1;i<=n;i++){
		scanf("%lld",&f[i]);
		high=max(high,f[i]); //ȡ�����ֵ 
		//low=min(low,f[i]);
	} long long u,v,w;
	low=max(f[1],f[n]); //�ؼ� ����Ϊʲô 
	for(int i=1;i<=m;i++){
		scanf("%lld%lld%lld",&u,&v,&w);
		add(u,v,w);add(v,u,w);
	}
}
void Dijkstra(int limit){
	fill(visited,visited+MAXN,0);
	fill(dist,dist+MAXN,INF);
	dist[1]=0;
	priority_queue<priority> q;
	q.push(priority{1,dist[1]});
	while(!q.empty()){
		priority tmp = q.top();q.pop();
		int tmpId = tmp.id;
		if(visited[tmpId]) continue;
		visited[tmpId]=1;
		for(int i=head[tmpId];i;i=edge[i].next){
			int targ = edge[i].to;
			if(f[targ]>limit) continue;
			dist[targ]=min(dist[targ],dist[tmpId]+edge[i].weight);
			if(!visited[targ]) q.push(priority{targ,dist[targ]});
		}
	}
}
int main(){
	init();long long flag=-1;
	while(low<=high){
		mid=(low+high)/2;
		Dijkstra(mid);
		if(dist[n]>b) low=mid+1;
		else high=mid-1,flag=mid;
	}
	if(flag==-1) printf("AFK");
	else printf("%lld",flag);
	return 0;
}






