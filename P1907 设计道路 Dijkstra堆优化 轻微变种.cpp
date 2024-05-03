#include<bits/stdc++.h>
#define MAXN 1005
#define MAXV 1000005
#define INF INT_MAX
using namespace std;
double dirt_unsatif,rome_unsatif;
int n;double Min_Sense=0.0;
bool visited[MAXN];double dist[MAXN];
struct nodes{
	double x;double y;
}a[MAXN];
struct node{
	int to;
	double weight;
	int next;
}edge[MAXV];int head[MAXN];int x=1;
void add(int u,int v,double w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
double GetDis(double x1,double y1,double x2,double y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
void init(){
	bool tmp_visited[MAXN][MAXN];
	fill(visited,visited+MAXN,0);
	fill(dist,dist+MAXN,INF);
	scanf("%lf%lf",&dirt_unsatif,&rome_unsatif);scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);
	}
	while(1){
		int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);
		if(tmp1==0 && tmp2==0) break;tmp_visited[tmp1][tmp2]=true;
		add(tmp1,tmp2,GetDis(a[tmp1].x,a[tmp1].y,a[tmp2].x,a[tmp2].y)*rome_unsatif);
		add(tmp2,tmp1,GetDis(a[tmp1].x,a[tmp1].y,a[tmp2].x,a[tmp2].y)*rome_unsatif);
	}
	scanf("%lf%lf",&a[0].x,&a[0].y);//下标0存码头 
	scanf("%lf%lf",&a[n+1].x,&a[n+1].y);//下标n+1存家
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=n+1;j++){
			if(i==j) continue;//去掉自环 
			if(!tmp_visited[i][j]){ //避免内容覆盖 
				add(i,j,GetDis(a[i].x,a[i].y,a[j].x,a[j].y)*dirt_unsatif);
				add(j,i,GetDis(a[i].x,a[i].y,a[j].x,a[j].y)*dirt_unsatif);
			}
		} 
}
struct priority{
	int id;
	double dists;
	friend bool operator <(priority a,priority b){
		return a.dists>b.dists;//从小到大的小根堆 
	}
};
priority_queue<priority>q;
void Dijkstra(){
	dist[0]=0;
	q.push(priority{0,0.0});
	while(!q.empty()){
		priority tmp = q.top();q.pop();
		int tmpid=tmp.id;
		if(visited[tmpid]==true) continue;
		visited[tmpid]=true;
		for(int i=head[tmpid];i;i=edge[i].next){
			int targ=edge[i].to;
			dist[targ]=min(dist[tmpid]+edge[i].weight,dist[targ]);
			if(!visited[targ]) q.push(priority{targ,dist[targ]});
		} 
	}
}
int main(){
	init();
	Dijkstra();
	printf("%.4lf",dist[n+1]);
	return 0;
}







 
