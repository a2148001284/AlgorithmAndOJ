#include<bits/stdc++.h>
using namespace std;
#define MAXV 10005
#define INF INT_MAX
//Dijkstra+堆优化+链式前向星
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];
bool visited[MAXV];
int x=1;long long dist[MAXV],path[MAXV];int n,m;int start_point,end_point;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}

struct priority{
	int id;
	int dis;
	bool operator < (const priority &x)const{
		return x.dis<dis;
	}
};
priority_queue<priority> q;

void init(){
	fill(dist,dist+MAXV,INF);
	fill(visited,visited+MAXV,0);
	fill(head,head+MAXV,0);
	cin>>n>>m;start_point=1;end_point=n;
	dist[start_point]=0;path[start_point]=0; //容易忘记写 
	for(int i=0;i<m;i++){
		int a,b,c;cin>>a>>b>>c;
		add(a,b,c);add(b,a,c);
	}
}

void Dijkstra(){
	q.push((priority){1,0});
	while(!q.empty()){
		priority temp = q.top();q.pop();
		if(!visited[temp.id]){
			visited[temp.id]=1;
			for(int i=head[temp.id];i;i=edge[i].next){
				if(dist[edge[i].to]>dist[temp.id]+edge[i].weight){
					dist[edge[i].to]=dist[temp.id]+edge[i].weight;
					path[edge[i].to]=temp.id;
					if(!visited[edge[i].to]) q.push((priority){edge[i].to,dist[edge[i].to]});
				}
			}
		}
	}
}

void Dispath(int xx){
	if(dist[n]==INF){
		cout<<-1;//不可达
		return; 
	}
	if(xx==start_point){
		cout<<xx<<" ";return;
	}
	Dispath(path[xx]);
	cout<<xx<<" ";
}

int main(){
	init();
	Dijkstra();
	Dispath(end_point);
	return 0;
}








 
