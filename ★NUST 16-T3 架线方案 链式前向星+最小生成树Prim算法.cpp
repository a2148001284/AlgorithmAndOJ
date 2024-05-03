#include<iostream>
#include<queue>
#include<limits.h> 
#include<algorithm>
using namespace std;
#define MAXV 100000
#define INF INT_MAX
//实现不了输入k输入多轮数据 这很弱智 也没必要 不至于设置成局部变量吧 多麻烦 
struct node{
	int to;  //边的终点 
	int weight; //边的权值 
	int next;  //与该边同起点的下一条边 
}edge[5*MAXV];
int head[MAXV]; //头数组 最近一次输入的以i为起点的边在edge数组中的下标 
int dis[MAXV];bool visited[MAXV];
int x=1;
void add(int u,int v,int w){
	edge[x].to = v;
	edge[x].weight = w;
	edge[x].next = head[u];
	head[u]=x++; 
}
void Prim(int n){
	for(int i=1;i<=n;i++) dis[i]=INT_MAX;dis[1]=0;
	fill(visited,visited+MAXV,0);
	for(int i=head[1];i;i=edge[i].next)  //更新边+无向边 取两个方向最小的 所以用min 
		dis[edge[i].to]=min(dis[edge[i].to],edge[i].weight);
	int total = 0;int now=1;int mins = INT_MAX;int ans=0;//ans为题目所求的长度之和 
	while(++total<n){ //最小生成树的边数等于点数-1 所以一共n-1次 
		visited[now]=1; mins=INT_MAX;
		for(int i=1;i<=n;i++){
			if(!visited[i] && dis[i]<mins){
				mins = dis[i];now = i;
			}
		}
		ans+=mins;
		for(int i=head[now];i;i=edge[i].next){
			int v = edge[i].to;
			if(dis[v]>edge[i].weight && !visited[v])
				dis[v] = edge[i].weight; 
		}
		if(total==n-1) visited[now]=1; 
	}
	for(int i=1;i<=n;i++){
		if(visited[i]!=1){
			cout<<-1; return;
		}
	}
	cout<<ans;
}
int main(){
	int time;cin>>time;
	for(int i=0;i<time;i++){
		int n,m;cin>>n>>m;
		for(int i=0;i<m;i++){
			int x,y,z;cin>>x>>y>>z;
			add(x+1,y+1,z);
			add(y+1,x+1,z); //★★★★★★无向图 点从-1开始 所以+1即可 
		}
		Prim(n);
	}
	return 0;
}





