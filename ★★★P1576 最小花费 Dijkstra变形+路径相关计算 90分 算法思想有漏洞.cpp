#include<bits/stdc++.h>
#define MAXN 4005
#define MAXV 200010 //�����ܱ���Ŀ���ķ�Χ��һ�� �Ͳ�������ˣ����� ��Ϊ�����Ҫ���������� ���Ա�Ҫ��Χx2 
#define INF INT_MAX
//���ۣ��ҵ���� �����· �ڵ���Ŀ�ĵ���̵�·���ҽڵ���������· 
//�������ǶԵ� �÷�90�� WAһ�� ԭ���� ������·�ĳ�����ͬ �ҵ�ĸ���Ҳ��ͬ ���Ҳ�᲻ͬ �������Ҫ�Ľ��㷨˼��ĵط��� 
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
			//�����ĺ���:������ֶ�����Ŀ����·�� ������Ŀ��Ҫ����Ҫ�󾡿��ܶ�ĵ�Ĳ��� 
			//�������money���� �����ж϶���һ���Ⱥ� ��ͨ���м�ڵ����ַ�����targ��dist[targ]���ʱ Ҳ��Ҫ����
			//�����Ϳ��Ը��¶�Ӧ��path �Ӷ��ҵ���ȷ��·�� 
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
	//printf("%.8lf",money);//long long��%lld double��%lf��%f ���С�������ְ취 
	cout<<fixed<<setprecision(8)<<money; //�ڶ������С���ķ��� 
	return 0; //110.64091356
}





