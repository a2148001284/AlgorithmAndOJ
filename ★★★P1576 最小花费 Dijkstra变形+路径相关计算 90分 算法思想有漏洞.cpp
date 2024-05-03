#include<bits/stdc++.h>
#define MAXN 4005
#define MAXV 200010 //尽可能比题目给的范围大一倍 就不会出错了！！！ 因为无向边要存两个方向 所以边要范围x2 
#define INF INT_MAX
//结论：我的理解 走最短路 在到达目的地最短的路中找节点最多的那条路 
//理论上是对的 得分90分 WA一个 原因是 如果最短路的长度相同 且点的个数也相同 结果也会不同 这个就需要改进算法思想的地方了 
using namespace std;
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];int head[MAXN];int x=1;int n,m;double money=100.0;
bool visited[MAXN];int path[MAXN];int dist[MAXN];int a,b;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmp1,tmp2,tmp3;scanf("%d%d%d",&tmp1,&tmp2,&tmp3);
		add(tmp1,tmp2,tmp3);add(tmp2,tmp1,tmp3);
	}
	scanf("%d%d",&a,&b);
	fill(visited,visited+MAXN,0);
	fill(dist,dist+MAXN,INF);
}
struct priority{
	int id;
	int dis;
	friend bool operator < (priority a,priority b){
		return a.dis>b.dis;
	}
};
priority_queue<priority>q;
void Dijkstra(){
	q.push(priority{a,0});dist[a]=0;path[a]=-1;
	while(!q.empty()){
		priority tmps = q.top();//cout<<"-->"<<q.top().id<<endl;
		q.pop();int tmpid=tmps.id;
		if(visited[tmpid]) continue;visited[tmpid]=1;
		for(int i=head[tmpid];i;i=edge[i].next){
			int targ=edge[i].to;int weig=edge[i].weight;
			//dist[i]=min(dist[i],dist[tmpid]+weig);
			//★★核心核心:如果出现多条到目标点的路径 根据题目的要求是要求尽可能多的点的参与 
			//这样最后money会少 所以判断多了一个等号 当通过中间节点这种方法到targ和dist[targ]相等时 也需要进入
			//这样就可以更新对应的path 从而找到正确的路径 
			if(dist[targ]>=dist[tmpid]+weig){  
				dist[targ]=dist[tmpid]+weig;//cout<<tmpid<<"--->"<<targ<<endl;
				path[targ]=tmpid;
				if(!visited[targ]) q.push(priority{targ,dist[targ]});
			}
		}
	}
}
void GetTarg(int pre,int now){
	if(pre!=-5){
		int i;for(i=head[pre];edge[i].to!=now;i=edge[i].next);
		//cout<<"-->"<<(100-edge[i].weight)*0.01<<endl;
		money/=((100-edge[i].weight)*0.01);
	}
	if(path[now]!=-1) GetTarg(now,path[now]);
}
int main(){
	init();
	Dijkstra();
	GetTarg(-5,b);
	//printf("%.8lf",money);//long long是%lld double是%lf或%f 输出小数有两种办法 
	cout<<fixed<<setprecision(8)<<money; //第二种输出小数的方法 
	return 0; //110.64091356
}





