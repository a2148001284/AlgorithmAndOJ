#include<iostream>
#include<queue>
#include<limits.h> 
#include<algorithm>
using namespace std;
#define MAXV 100000
#define INF INT_MAX
struct node{
	int to;  //�ߵ��յ� 
	int weight; //�ߵ�Ȩֵ 
	int next;  //��ñ�ͬ������һ���� 
}edge[5*MAXV];
int head[MAXV]; //ͷ���� ���һ���������iΪ���ı���edge�����е��±� 
int dis[MAXV];bool visited[MAXV];
int x=1;//add���õ����м��� �ߵ���� ��1��ʼ���߱�� 
void add(int u,int v,int w){
	edge[x].to = v;
	edge[x].weight = w;
	edge[x].next = head[u];
	head[u]=x++; 
}
void Prim(int n){
	//fill(dis,dis+MAXV,INT_MAX); //dis�����ʼ�� 
	for(int i=2;i<=n;i++) dis[i]=INT_MAX;dis[1]=0;
	fill(visited,visited+MAXV,0);
	for(int i=head[1];i;i=edge[i].next)  //���±�+����� ȡ����������С�� ������min 
		dis[edge[i].to]=min(dis[edge[i].to],edge[i].weight);
	int total = 0;int now=1;int mins = INT_MAX;int ans=0;//ansΪ��Ŀ����ĳ���֮�� 
	while(++total<n){ //��С�������ı������ڵ���-1 ����һ��n-1�� 
		visited[now]=1; mins=INT_MAX;
		for(int i=1;i<=n;i++){
			if(!visited[i] && dis[i]<mins){
				mins = dis[i];now = i;
			}
		}
		//cout<<"mins:"<<mins<<" now:"<<now<<endl;
		ans+=mins;
		for(int i=head[now];i;i=edge[i].next){
			int v = edge[i].to;
			if(dis[v]>edge[i].weight && !visited[v])
				dis[v] = edge[i].weight; 
		}
		if(total==n-1) visited[now]=1; 
	}
	for(int i=1;i<=n;i++){
		if(visited[i]!=1){
			//cout<<ans<<endl;
			cout<<"orz";return;
		}
	}
	cout<<ans;
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		add(x,y,z);
		add(y,x,z); //�������
	}
	Prim(n);
	return 0;
}







