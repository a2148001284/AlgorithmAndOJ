#include<iostream>
#include<queue>
#include<limits.h> 
using namespace std;
#define MAXV 1000005
//#define INF 0x3f3f3f3f
//int的上限是 2147483647 为2的31次方-1 一般可以直接用 INT_MAX  也有0x3f3f3f3f 0x7f7f7f7f 
#define INF INT_MAX
//邻接矩阵会炸 
//链式前向星存图+堆优化Dijkstra 
/**********************/
struct node{
	int to;  //边的终点 
	int weight; //边的权值 
	int next;  //与该边同起点的下一条边 
}edge[10*MAXV];
int head[MAXV]; //头数组 最近一次输入的以i为起点的边在edge数组中的下标 
int x=1;//add中用到的中间量 边的序号 从1开始给边标号 
int n,m,start_point,end_point;

bool visited[MAXV]={0};
long long dist[MAXV],path[MAXV]; //path用于存路径 

//struct priority{
//	int dists; //最短距离 
//	int id;  //节点的编号 
//	bool operator < (const priority &x)const{ //重载 从小到大排序 默认是从大大小 
//		return x.dists<dists;
//	}
//};
//priority_queue<priority> q;

//这种friend的写法也可以 切记从小到大要写成< 和 > 
struct priority{
	int dists; //最短距离 
	int id;  //节点的编号 
	friend bool operator < (priority a,priority b){ //重载 从小到大排序 默认是从大到小 
		return a.dists>b.dists;
	}
};
priority_queue<priority> q;

void add(int u,int v,int w){
	edge[x].to = v;
	edge[x].weight = w;
	edge[x].next = head[u];
	head[u]=x++; 
}

void init(){
	fill(dist,dist+MAXV,INF);
	fill(head,head+MAXV,0);
	cin>>n>>m>>start_point;end_point=n;//自行设定起始点和结束点 
	dist[start_point]=0; //0这个点很重要 切记 
	path[start_point]=0;
	for(int i=0;i<m;i++){
		int temp1,temp2,temp3;cin>>temp1>>temp2>>temp3;
		add(temp1,temp2,temp3);
	}
}

void Dijkstra(int v){
	q.push((priority){0,v});int tempId;
	while(!q.empty()){
		priority temp = q.top();q.pop();
		tempId = temp.id;
		if(!visited[tempId]){
			visited[tempId]=1;
			for(int i=head[tempId];i;i=edge[i].next){
				int v=edge[i].to;
				if(dist[v]>dist[tempId]+edge[i].weight){
					dist[v]=dist[tempId]+edge[i].weight;
					path[v]=tempId;
					if(!visited[v]) q.push((priority){dist[v],v});
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
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl; //展示每个节点的dis数值 
	//Dispath(end_point);//展示路径 
	return 0;
}
