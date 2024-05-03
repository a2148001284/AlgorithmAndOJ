#include<bits/stdc++.h>
using namespace std;
#define MAXV 5000
#define INF INT_MAX
/** ��ʽǰ���� */
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];
int dis[MAXV],visited[MAXV];
int x=1;int n,m;
void add(int u,int v,int w){
	edge[x].to=v;
	edge[x].weight=w;
	edge[x].next=head[u];
	head[u]=x++;
}

/** ��ʼ�� */
void init(){
	cin>>n>>m;
	for(int i=0;i<m;i++){
		//���д�0��ʼ ����ÿ����ֵҪ��һ ���۲���
		int a,b,c;cin>>a>>b>>c;
		add(a+1,b+1,c);
		add(b+1,a+1,c); 
	}
} 

/** Prim�㷨 */
void Prim(){
	/** ��һ����ʼ�� ����Ĭ�ϴӵ�1��Ϊ���*/
	fill(dis,dis+MAXV,INF);
	fill(visited,visited+MAXV,0);
	dis[1]=0;
	for(int i=head[1];i;i=edge[i].next){
		dis[edge[i].to]=min(dis[edge[i].to],edge[i].weight);
	}
	/** Prim���� */
	int total=0;int now=1;int mins=INF;int ans=0;
	while(++total<=n-1){
		visited[now]=1;mins=INF;
		//������dis��δ���ʵ����Сdisֵ�ĵ� 
		for(int i=1;i<=n;i++)
			if(!visited[i] && dis[i]<mins){
				mins=dis[i];now=i;
			}
		ans+=mins;//ѡ�к� �������� ��visҪ��һ����Ϊ1 
		//�������now�ڵ������dis���� ��ͬ��Dijkstra�ĸ��� 
		for(int i=head[now];i;i=edge[i].next)
			if(dis[edge[i].to] > edge[i].weight && !visited[edge[i].to]) 
				dis[edge[i].to] = edge[i].weight;
		if(total == n-1) visited[now]=1;//���һ�ֵ�nowҪ������1 ������һ�ֻ�©�� 
	}
	/** ���ͼ�Ƿ���ڲ���ͨ������������ */
	for(int i=1;i<=n;i++)
		if(visited[i]!=1){
			cout<<"ͼ����ͨ";
			return;
		} 
	cout<<ans; //��С������� 
} 

int main(){
	init();
	Prim();
	return 0;
}











