#include<bits/stdc++.h>
using namespace std;
#define MAXV 5005
#define MAXE 200005
#define INF INT_MAX
//Kruskal算法标准模板 并查集+链式存储 
struct node{
	int u;int v;int w;
}edge[MAXE];int fa[MAXV];
bool cmp(node a,node b){
	return a.w<b.w;
}
int n,m;
void init(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<m;i++){
		int tmp1,tmp2,tmp3;scanf("%d %d %d",&tmp1,&tmp2,&tmp3);
		edge[i].u=tmp1;edge[i].v=tmp2;edge[i].w=tmp3;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	fa[find(x)]=find(y);
}
void kruskal(){
	sort(edge,edge+m,cmp);
	int ans=0;int cnt=0;
	for(int i=0;i<m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		if(find(u)!=find(v)){
			merge(u,v);
			ans+=w;cnt++;
			if(cnt==n-1){
				printf("%d",ans);return;
			} //n-1条边 
		}
	}
	printf("orz");return;
}

int main(){
	init();
	kruskal();
	return 0;
}







