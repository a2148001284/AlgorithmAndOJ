#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#define MAXN 5005
#define MAXV 200005
using namespace std;
struct node{
	int u,v,w;
}edge[MAXV];int fa[MAXN];int n,m,ans=0;
int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
bool cmp(node a,node b){
	return a.w<b.w;
}
void Kruskal(){
	sort(edge+1,edge+m+1,cmp);int line=0;
	for(int i=1;i<=m;i++){
		int to=edge[i].v;int f=edge[i].u;
		if(find(to)==find(f)) continue;
		merge(to,f);line++;ans+=edge[i].w;
		if(line==n-1){
			printf("%d",ans);return;
		}
	}
	printf("orz");return;//遍历完所有边 也选不出n-1条边 说明不连通 
}
int main(){
	scanf("%d%d",&n,&m);int id=0;
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c); 
		edge[++id].u=a;edge[id].v=b;edge[id].w=c;
	}
	for(int i=1;i<=n;i++) fa[i]=i;
	Kruskal();
	return 0;
}

