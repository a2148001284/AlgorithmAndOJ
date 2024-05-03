#include<bits/stdc++.h>
using namespace std;
#define MAXV 4000005
#define INF INT_MAX
inline int qread()                      //依然是快读  本次卡TLE主要就是cin和cout很慢 用快读就可以AC 用scanf也可以过 
{
    char c=getchar();int num=0,f=1;
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) num=num*10+c-'0';
    return num*f;
}
struct node{
	int to;
	int weight;
	int next;
}edge[MAXV];
int head[MAXV];bool visited[MAXV];int x=1;
int dis[MAXV];//int path[MAXV];
int n,m;long long line[MAXV];
void add(int u,int v){
	edge[x].to=v;
	edge[x].weight=1;
	edge[x].next=head[u];
	head[u]=x++;
}
void init(){
	//n=qread();m=qread();
	scanf("%d",&n);scanf("%d",&m); 
	for(int i=1;i<=m;i++){
		int tmp1,tmp2;scanf("%d",&tmp1);scanf("%d",&tmp2);
		//tmp1=qread();tmp2=qread();
		add(tmp1,tmp2);add(tmp2,tmp1);
	}
	fill(visited,visited+MAXV,0);
	fill(dis,dis+MAXV,INF);
	fill(line,line+MAXV,0);
	//visited[1]=1;  这里不能先visit 否则后续少了一轮处理 
	dis[1]=0;//path[1]=0;
	line[1]=1;
}
struct priority{
	int id;
	int dists;
	friend bool operator <(priority a,priority b){
		return a.dists>b.dists;
	}
};
priority_queue<priority> q;
void Dijkstra(){
	q.push(priority{1,0});
	while(!q.empty()){
		priority tmp = q.top();q.pop();
		if(!visited[tmp.id]){
			visited[tmp.id]=1;
			int tmpid=tmp.id;
			for(int i=head[tmpid];i;i=edge[i].next){
				int tmpto=edge[i].to;
				if(dis[tmpid]+edge[i].weight<dis[tmpto]){
					dis[tmpto]=dis[tmpid]+edge[i].weight;
					line[tmpto]=line[tmpid];
					if(!visited[tmpto]) q.push(priority{tmpto,dis[tmpto]});
				}else if(dis[tmpid]+edge[i].weight==dis[tmpto]){
					line[tmpto]+=line[tmpid];
					line[tmpto]%=100003;  //数据太大 如果全部加完后最后取余 longlong也会爆炸 所以每次都取余 
				}
			}
		}
	}
}
int main(){
	init();
	Dijkstra();
	for(int i=1;i<=n;i++){
		if(line[i]){
			cout<<line[i]%100003<<endl;
		}else cout<<0<<endl;
	}
	return 0;
}








