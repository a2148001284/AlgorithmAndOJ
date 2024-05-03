#include<bits/stdc++.h>
using namespace std;
#define MAXV 10001
#define INF INT_MAX
/** ��ʽǰ����+Dijkstra+���Ż��洢 */
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];
bool visited[MAXV]={0};
long long dis[MAXV],path[MAXV]; //path���ڴ���һ���ڵ� ��Ҫ�Ǵ�·�� 

int x=1;
void add(int u,int v,int w){
	edge[x].to = v;
	edge[x].weight = w;
	edge[x].next = head[u];
	head[u]=x++;
}
int n,m;

/** ��-->���ȼ����� */
struct priority{
	int dists; //dis ����Ҫ��������� ����Ҫ���� 
	int id;//�ڵ�ı�� 
	bool operator < (const priority &x)const{
		return x.dists<dists;
	}
};
priority_queue<priority> q;


/** Dijkstra */
void Dijkstra(int start){
	q.push((priority){0,start}); //����q�� ����ÿ��ȡ��������dist��С�� 
	int temp;
	while(!q.empty()){
		priority temps = q.top();q.pop();
		temp = temps.id;
		if(!visited[temp]){
			visited[temp]=1;
			for(int i=head[temp];i;i=edge[i].next){ //Ҫ����ĵ��1��ʼ 
				int v = edge[i].to;
				if(dis[v]>dis[temp]+edge[i].weight){
					dis[v]=dis[temp]+edge[i].weight;
					//cout<<"->"<<dis[v]<<endl;
					if(!visited[v]) q.push(priority{dis[v],v}); //�õ�������bfs���� 
				}
			}
		} 
	}
}

void init(){
	fill(visited,visited+MAXV,0);
	fill(dis,dis+MAXV,INF);
	fill(head,head+MAXV,0);
	cin>>n>>m;//��Ŀ��nΪ������ mΪstart�ڵ� ��Ϊn-1 
	dis[m]=0; //����disΪ0 ����Ҫ 
	for(int i=0;i<n-1;i++){
		int a,b;cin>>a>>b;
		add(a,b,1);add(b,a,1);
	}
}	

void res(){
	int max=0;
	for(int i=1;i<=n;i++){
		//cout<<dis[i]<<endl;
		if(dis[i]>max && dis[i]!=INF) max=dis[i];
	}
	cout<<max;
}

int main(){
	init();
	Dijkstra(m);
	res();
	return 0;
}




