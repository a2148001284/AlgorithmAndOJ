#include<bits/stdc++.h>
using namespace std;
//������·��ӵ�������ֵ��С
//����2:Dijkstra+���Ż�+��ʽǰ���� ���� 
//̰�Ĳ���:dis����洢��ÿ���ڵ�����ӵ���� ��С������ÿ��ѡ���ӵ������С�Ľ�����չ����(���Prim�㷨)
//����һ���� �����ӵ���ȵ���Сֵ�����������ĵ�ĸ�ֵ���ֵȡ��maxֵ ������max��ȡ��С  
int n,m,s,t;
#define MAXN 30005  //�࿪�� ���ܾͲ����� 
#define INF 0x3f3f3f3f
struct node{
	int to;int weight;int next;
}edge[MAXN];bool visited[MAXN];int head[MAXN];int x=1;int dis[MAXN];//�����洢���ڵ�����ӵ���� 
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}
struct priority{
	int id;
	int dist;
	friend bool operator <(priority a,priority b){//Ĭ��Ϊ����� �෴ΪС���� 
		return a.dist>b.dist;
	}
};
priority_queue<priority> q;
void Dijkstra(){
	q.push(priority{s,0});
	while(!q.empty()){
		priority tmp = q.top();q.pop();int tmpId=tmp.id;
		if(visited[tmpId]) continue; visited[tmpId]=1;
		for(int i=head[tmpId];i;i=edge[i].next){
			int targ = edge[i].to;int maxs=max(dis[tmpId],edge[i].weight);//��ǰ��tmpId->targ֮��� targ�����ӵ����Ϊmaxs 
			if(maxs<dis[targ]) dis[targ]=maxs;//�����к�targ��ص������ ȡ��Сֵ ���������ӵ������ȡ��С�� 
			if(!visited[targ]) q.push(priority{targ,dis[targ]});
		}
	}
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);add(a,b,c);add(b,a,c);
	}
	fill(visited,visited+MAXN,0);
	fill(dis,dis+MAXN,INF);dis[s]=0;
	Dijkstra();printf("%d",dis[t]);
	return 0;
}









