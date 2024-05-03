#include<iostream>
using namespace std;
#define MAXV 502
#define INF 0x3f3f3f3f
typedef int EdgeType;
typedef char VertexType;
typedef struct{
	VertexType Vex[MAXV];
	EdgeType Edge[MAXV][MAXV]; 
	//EdgeType Edge[MAXV][MAXV]={INF}; ���ָ�ֵ ���ûд ֵ���������
	//���д��={0} ȫ��Ϊ0  ���д����������={999} ֻ�е�һ���ᱻ��ֵ ����Ҫ��memset����fill����ֵ 
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
	end_point=n;start_point=1;//�����趨�����յ� 
	G.vexnum=n;G.egdesum=m;
	for(int i=0;i<m;i++){
		int temp1,temp2,temp3;cin>>temp1>>temp2>>temp3;
		G.Edge[temp1][temp2]=temp3;
	}
}

void Dijkstra(int v){
	visited[v]=1;path[v]=0;dist[v]=0;
	//start_point = v;
	//���������ص�dist��path��Ϣ 
	for(int i=1;i<=G.vexnum;i++){  //�����Ǵ����㣬i���Ƕ��� �ʴ�1��ʼ 
		dist[i]=G.Edge[v][i];
		if(G.Edge[v][i]<INF) path[i]=v;
		else path[i]=-1;
	}
	int mindis=INF,u;
	for(int i=0;i<G.vexnum;i++){
		mindis=INF;
		//�ҵ�δ�����ʵ�dist��С�Ľڵ� �浽u�� �����öѵķ�ʽ�Ż� 
		for(int j=1;j<=G.vexnum;j++){
			if(visited[j]==0 && dist[j]<mindis){
				u=j;mindis=dist[j];
			}
		}
		visited[u]=1;
		//Dijkstra�����㷨 
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



