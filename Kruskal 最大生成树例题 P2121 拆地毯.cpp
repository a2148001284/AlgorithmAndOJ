#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
//Kruskal最大生成树算法 并查集+链式存储
struct node{
	int u,v,w;
}edge[MAXN];int fa[MAXN];
int n,m,k;

void init(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		edge[i].u=a;edge[i].v=b;edge[i].w=c;//只存一个方向 无向图 无所谓u和v 
	}
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
//void merge(int x,int y){
//	fa[find(x)]=find(y);
//}
bool cmp(node a,node b){
	return a.w>b.w;
}
void Kruskal(){
	sort(edge,edge+m,cmp); //从大到小排序所有的边 
	int ans=0;int flag=0; 
	for(int i=0;i<m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u);int fv=find(v);
		if(fu==fv) continue; //同一个节点 已经在集合中 
		ans+=w;fa[fu]=fv;flag++;
		if(flag==k){ //错误:i==k-1 不一定前面的边都加进去了 只有增加的才可以统计 
			printf("%d",ans);break;
		}
	}
}
int main(){
	init();
	Kruskal();
	return 0;
}
 
 










