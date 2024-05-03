#include<bits/stdc++.h>
using namespace std;
#define MAXV 10001
#define INF INT_MAX
/** 链式前向星+Dijkstra+堆优化存储 */
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];
bool visited[MAXV]={0};
long long dis[MAXV],path[MAXV]; //path用于存上一个节点 主要是存路径 

int x=1;
void add(int u,int v,int w){
	edge[x].to = v;
	edge[x].weight = w;
	edge[x].next = head[u];
	head[u]=x++;
}
int n,m;

/** 堆-->优先级队列 */
struct priority{
	int dists; //dis 由于要用这个排序 所以要加上 
	int id;//节点的编号 
	bool operator < (const priority &x)const{
		return x.dists<dists;
	}
};
priority_queue<priority> q;


/** Dijkstra */
void Dijkstra(int start){
	q.push((priority){0,start}); //放入q中 这样每次取出来就是dist最小的 
	int temp;
	while(!q.empty()){
		priority temps = q.top();q.pop();
		temp = temps.id;
		if(!visited[temp]){
			visited[temp]=1;
			for(int i=head[temp];i;i=edge[i].next){ //要求传入的点从1开始 
				int v = edge[i].to;
				if(dis[v]>dis[temp]+edge[i].weight){
					dis[v]=dis[temp]+edge[i].weight;
					//cout<<"->"<<dis[v]<<endl;
					if(!visited[v]) q.push(priority{dis[v],v}); //用的是类似bfs策略 
				}
			}
		} 
	}
}

void init(){
	fill(visited,visited+MAXV,0);
	fill(dis,dis+MAXV,INF);
	fill(head,head+MAXV,0);
	cin>>n>>m;//题目中n为顶点数 m为start节点 边为n-1 
	dis[m]=0; //起点的dis为0 很重要 
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		add(a,b,1);add(b,a,1);
	}
}	

void res(){
	int max=0;
	for(int i=1;i<=n;i++){
		//cout<<dis[i]<<endl;
		if(dis[i]>max && dis[i]!=INF) max=dis[i];
	}
	cout<<max;
}

int main(){
	init();
	Dijkstra(m);
	res();
	return 0;
}




