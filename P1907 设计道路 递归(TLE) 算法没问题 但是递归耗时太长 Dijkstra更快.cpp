#include<bits/stdc++.h>
#define MAXN 10050
#define INF INT_MAX
using namespace std;
double dirt_unsatif,rome_unsatif;
int n;double Min_Sense=INF;
struct node{
	int id;double x;double y;
}a[MAXN];
//3个AC 还有两个TLE 因为递归复杂度高 需要使用Dijkstra才能过AC 但是至少算法是没有问题的 
bool Is_Rome_Road[MAXN][MAXN];
bool visited[MAXN];
void init(){
	scanf("%lf%lf",&dirt_unsatif,&rome_unsatif);
	scanf("%d",&n);
	for(int i=2;i<=n+1;i++){
		scanf("%lf%lf",&a[i].x,&a[i].y);a[i].id=i;
	}
	while(1){
		int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);
		if(tmp1==0 && tmp2==0) break;
		Is_Rome_Road[tmp1+1][tmp2+1]=true;
		Is_Rome_Road[tmp2+1][tmp1+1]=true;
	}
	scanf("%lf%lf",&a[1].x,&a[1].y);
	scanf("%lf%lf",&a[n+2].x,&a[n+2].y);
	a[1].id=1;a[n+2].id=n+2;
}
double GetDis_Sense(node a,node b){
	if(Is_Rome_Road[a.id][b.id]==1 || Is_Rome_Road[b.id][a.id]==1){
		return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))*rome_unsatif;	
	}else return (sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)))*dirt_unsatif;	
}
void dfs(node &s,node &t,double Now_Sense){
	if(s.id==t.id) return; //去自环 
	visited[t.id]=1;Now_Sense+=GetDis_Sense(s,t);
	if(t.x==a[n+2].x&&t.y==a[n+2].y){
		//cout<<Now_Sense<<endl;
		visited[t.id]=0; //很关键 否则会堵死其它节点到终点的路 
		Min_Sense=min(Min_Sense,Now_Sense);return;
	}
	for(int i=1;i<=n+2;i++){
		if(visited[i]==true) continue;
		if(t.x==a[i].x && t.y==a[i].y) continue; 
		dfs(t,a[i],Now_Sense);
	}
	visited[t.id]=0;
}
int main(){
	init();visited[1]=1;
	for(int i=2;i<=n+2;i++) dfs(a[1],a[i],0.0);
	printf("%.4lf",Min_Sense);
	return 0;
}






