#include<bits/stdc++.h>
using namespace std;
#define MAXV 5000
#define INF INT_MAX
/** 链式前向星 */
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];
int dis[MAXV],visited[MAXV];
int x=1;int n,m;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}

/** 初始化 */
void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		//城市从0开始 所以每个数值要加一 代价不变
		int a,b,c;cin>>a>>b>>c;
		add(a+1,b+1,c);
		add(b+1,a+1,c); 
	}
} 

/** Prim算法 */
void Prim(){
	/** 进一步初始化 这里默认从点1作为起点*/
	fill(dis,dis+MAXV,INF);
	fill(visited,visited+MAXV,0);
	dis[1]=0;
	for(int i=head[1];i;i=edge[i].next){
		dis[edge[i].to]=min(dis[edge[i].to],edge[i].weight);
	}
	/** Prim部分 */
	int total=0;int now=1;int mins=INF;int ans=0;
	while(++total<=n-1){
		visited[now]=1;mins=INF;
		//找所有dis中未访问点的最小dis值的点 
		for(int i=1;i<=n;i++)
			if(!visited[i] && dis[i]<mins){
				mins=dis[i];now=i;
			}
		ans+=mins;//选中后 长度增加 而vis要下一轮置为1 
		//更新这个now节点后续的dis内容 不同于Dijkstra的更新 
		for(int i=head[now];i;i=edge[i].next)
			if(dis[edge[i].to] > edge[i].weight && !visited[edge[i].to]) 
				dis[edge[i].to] = edge[i].weight;
		if(total == n-1) visited[now]=1;//最后一轮的now要单独置1 否则下一轮会漏掉 
	}
	/** 检测图是否存在不连通的其它点等情况 */
	for(int i=1;i<=n;i++)
		if(visited[i]!=1){
			cout<<"图不连通";
			return;
		} 
	cout<<ans; //最小代价输出 
} 

int main(){
	init();
	Prim();
	return 0;
}











