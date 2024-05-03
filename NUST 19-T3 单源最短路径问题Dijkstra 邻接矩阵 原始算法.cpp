#include<iostream>
using namespace std;
#define MAXV 502
#define INF 0x3f3f3f3f
typedef int EdgeType;
typedef char VertexType;
typedef struct{
	VertexType Vex[MAXV];
	EdgeType Edge[MAXV][MAXV]; 
	//EdgeType Edge[MAXV][MAXV]={INF}; 这种赋值 如果没写 值都是随机数
	//如果写了={0} 全部为0  如果写的是其它数={999} 只有第一个会被赋值 所以要用memset或者fill赋初值 
	int vexnum,egdesum;
}MGraph;
bool visited[MAXV]={0};
int dist[MAXV],path[MAXV]; //int dist[MAXV]={INF}
MGraph G;
int start_point;
int end_point;

void init(){
	fill(dist,dist+MAXV,INF);
	fill(G.Edge[0],G.Edge[0]+MAXV*MAXV,INF);
	int n,m;cin>>n>>m;
	end_point=n;start_point=1;//自行设定起点和终点 
	G.vexnum=n;G.egdesum=m;
	for(int i=0;i<m;i++){
		int temp1,temp2,temp3;cin>>temp1>>temp2>>temp3;
		G.Edge[temp1][temp2]=temp3;
	}
}

void Dijkstra(int v){
	visited[v]=1;path[v]=0;dist[v]=0;
	//start_point = v;
	//更新起点相关的dist和path信息 
	for(int i=1;i<=G.vexnum;i++){  //由于是处理顶点，i就是顶点 故从1开始 
		dist[i]=G.Edge[v][i];
		if(G.Edge[v][i]<INF) path[i]=v;
		else path[i]=-1;
	}
	int mindis=INF,u;
	for(int i=0;i<G.vexnum;i++){
		mindis=INF;
		//找到未被访问的dist最小的节点 存到u中 可以用堆的方式优化 
		for(int j=1;j<=G.vexnum;j++){
			if(visited[j]==0 && dist[j]<mindis){
				u=j;mindis=dist[j];
			}
		}
		visited[u]=1;
		//Dijkstra核心算法 
		for(int k=1;k<=G.vexnum;k++){
			if(visited[k]==0){
				if(G.Edge[u][k]!=INF && dist[u]+G.Edge[u][k]<dist[k]){
					dist[k]=dist[u]+G.Edge[u][k];
					path[k]=u;
				}  
			}
		}
	}
}

void Dispath(int v){
	if(v==start_point){
		cout<<v<<" ";
		return;
	}
	Dispath(path[v]);
	cout<<v<<" ";
}

int main(){
	init();
	Dijkstra(start_point);
	cout<<dist[end_point]<<endl;
	Dispath(end_point);
	return 0;
}



