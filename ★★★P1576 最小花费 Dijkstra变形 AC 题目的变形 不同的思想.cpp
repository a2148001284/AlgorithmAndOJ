#include<bits/stdc++.h>
#define MAXN 4005
#define MAXV 200010 //�����ܱ���Ŀ���ķ�Χ��һ�� �Ͳ�������ˣ����� ��Ϊ�����Ҫ���������� ���Ա�Ҫ��Χx2 
#define INF 0x3f3f3f3f
//����˼�룬ÿ�����ϴ�(1-z%) ��һֱ·���ϸ���Ȩ�˻������ֵ
//֮����100/max���� �ѵ㣺 ��������ǳ˻������Ǽӷ� 
//�Ķ����� 1.���洢��Ȩ�˻������ֵ �����Ǿ���ĺ͵�(��Ҫһ��������Ŀ��������)
//2.����Ȩֵ�Ӵ�С���� ����Ҫ����Ϊͬ�� 3.Dijkstra�ĸ���������ͬ  4.dist���鸳ֵ����Ϊ������ Ҫ�͸�ֵ�������� 
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
	fill(dist,dist+MAXN,-INF);//�ȴ�� ����Ҫ��-INF 
}
struct priority{
	int id;
	double dis;
	//Ĭ����� ��� ����Ȩֵ��Ľ������� ������struct ��ʹ��Ĭ���Ǵ�� Ҳ��Ҫ��д ����ֻ��һ�����ڵ���int,double�� 
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




