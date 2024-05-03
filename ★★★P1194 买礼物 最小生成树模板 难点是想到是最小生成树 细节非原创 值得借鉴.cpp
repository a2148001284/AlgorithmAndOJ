#include<bits/stdc++.h>
using namespace std;
int A,B;//B个东西 每个A元 
//1.关闭O2优化 否则会出问题  2.Kruskal建立图 必须单向建立 双向也行 但是没必要 sort以后会有很多重复判断 
//★给每个节点加一个0到该节点的边 且权值为A 这样如果边权大于A 可以优先考虑A本身的数值加法 
struct node{
	int u,v,w;
}edge[250000];int ans=0;int id=0;int fa[505];//bool visited[505];
void init(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=B;i++) for(int j=1;j<=B;j++){
		int tmp;scanf("%d",&tmp);if(i==j || tmp==0) continue;//边权为0都不建立边 
		if(i<j) edge[++id].u=i,edge[id].v=j,edge[id].w=tmp;
	}
	for(int i=0;i<=505;i++) fa[i]=i;
	//fill(visited,visited+505,0);
	for(int i=1;i<=B;i++) edge[++id].u=0,edge[id].v=i,edge[id].w=A;//★ 
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
bool cmp(node a,node b){
	return a.w<b.w;//从小到大 
}
void Kruskal(){
	sort(edge+1,edge+id+1,cmp);int cnt=1;
	for(int i=1;i<=id&&cnt<=B;i++){ //id条边 B个点 只要line为B-1条边就可以得到最小生成树了 
		int from=edge[i].u;int to=edge[i].v;
		//if(A+edge[i].w>A+A) break;//避免边权比A还大 这种就不用选了 但是不太对 因为可以连续买 
		if(find(from)!=find(to)) 
			merge(from,to),ans+=edge[i].w,cnt++;//visited[from]=1,visited[to]=1;
	}
	//如果还没有结束 说明有的点间的距离是0 这些点需要单独加上
//	for(int i=1;i<=B;i++) if(!visited[i]) ans+=A;
//	if(id>=1) ans+=A; printf("%d",ans); 
}
int main(){
	init();
	Kruskal();printf("%d",ans);
	return 0;
}


