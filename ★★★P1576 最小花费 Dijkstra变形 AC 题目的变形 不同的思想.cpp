#include<bits/stdc++.h>
#define MAXN 4005
#define MAXV 200010 //尽可能比题目给的范围大一倍 就不会出错了！！！ 因为无向边要存两个方向 所以边要范围x2 
#define INF 0x3f3f3f3f
//真正思想，每条边上存(1-z%) 求一直路径上各边权乘积的最大值
//之后用100/max即可 难点： 理解这题是乘积而不是加法 
//改动在于 1.结点存储边权乘积的最大值 而不是距离的和等(需要一定对于题目的理解才行)
//2.按照权值从大到小排序 所以要重载为同号 3.Dijkstra的更新条件不同  4.dist数组赋值不能为正无穷 要和赋值条件契合 
using namespace std;
struct node{
	int to;
	double weight;
	int next;
}edge[MAXV];int head[MAXN];int x=1;int n,m;double money=100.0;
bool visited[MAXN];double dist[MAXN];int a,b;
void add(int u,int v,double w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmp1,tmp2,tmp3;scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
		double tmp4=1-0.01*tmp3;
		add(tmp1,tmp2,tmp4);add(tmp2,tmp1,tmp4);
	}
	scanf("%d%d",&a,&b);
	fill(visited,visited+MAXN,0);
	fill(dist,dist+MAXN,-INF);//比大边 所有要用-INF 
}
struct priority{
	int id;
	double dis;
	//默认情况 大堆 按照权值大的进行排序 由于是struct 即使堆默认是大堆 也需要重写 除非只是一个存在的如int,double等 
	friend bool operator < (priority a,priority b){
		return a.dis<b.dis; 
	}
};
priority_queue<priority>q;
void Dijkstra(){
	q.push(priority{a,1.0});dist[a]=1.0;
	while(!q.empty()){
		priority tmps = q.top();q.pop();int tmpid=tmps.id;
		if(visited[tmpid]) continue;visited[tmpid]=1;
		for(int i=head[tmpid];i;i=edge[i].next){
			int targ=edge[i].to;double weig=edge[i].weight;
			dist[targ]=max(dist[targ],dist[tmpid]*weig); 
			if(!visited[targ]) q.push(priority{targ,dist[targ]});
		}
	}
}
int main(){
	init();
	Dijkstra();
	printf("%.8lf",100.0/dist[b]);
	return 0;
}




