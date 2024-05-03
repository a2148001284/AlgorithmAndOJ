#include<iostream>
#include<queue>
#include<limits.h> 
using namespace std;
#define MAXV 1000005
//#define INF 0x3f3f3f3f
//int�������� 2147483647 Ϊ2��31�η�-1 һ�����ֱ���� INT_MAX  Ҳ��0x3f3f3f3f 0x7f7f7f7f 
#define INF INT_MAX
//�ڽӾ����ը 
//��ʽǰ���Ǵ�ͼ+���Ż�Dijkstra 
/**********************/
struct node{
	int to;  //�ߵ��յ� 
	int weight; //�ߵ�Ȩֵ 
	int next;  //��ñ�ͬ������һ���� 
}edge[10*MAXV];
int head[MAXV]; //ͷ���� ���һ���������iΪ���ı���edge�����е��±� 
int x=1;//add���õ����м��� �ߵ���� ��1��ʼ���߱�� 
int n,m,start_point,end_point;

bool visited[MAXV]={0};
long long dist[MAXV],path[MAXV]; //path���ڴ�·�� 

//struct priority{
//	int dists; //��̾��� 
//	int id;  //�ڵ�ı�� 
//	bool operator < (const priority &x)const{ //���� ��С�������� Ĭ���ǴӴ��С 
//		return x.dists<dists;
//	}
//};
//priority_queue<priority> q;

//����friend��д��Ҳ���� �мǴ�С����Ҫд��< �� > 
struct priority{
	int dists; //��̾��� 
	int id;  //�ڵ�ı�� 
	friend bool operator < (priority a,priority b){ //���� ��С�������� Ĭ���ǴӴ�С 
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
	cin>>n>>m>>start_point;end_point=n;//�����趨��ʼ��ͽ����� 
	dist[start_point]=0; //0��������Ҫ �м� 
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
	for(int i=1;i<=n;i++) cout<<dist[i]<<" ";cout<<endl; //չʾÿ���ڵ��dis��ֵ 
	//Dispath(end_point);//չʾ·�� 
	return 0;
}
