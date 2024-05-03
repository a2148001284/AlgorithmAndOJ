#include<bits/stdc++.h>
using namespace std;
int A,B;//B个东西 每个A元 
//核心：要可以看出来 这道题考的其实是最小生成树
//用Kruskal更简单 但是需要找到那些没有被加入集合的点单独计算 
//用Prim也可行 有visited也很方便达到目标 
//1.关闭O2优化 否则会出问题  2.Kruskal建立图 必须单向建立 双向也行 但是没必要 sort以后会有很多重复判断 
//自己算法问题:1.洛谷问题 要关闭02优化 2.edge要开很大 一直容易错 因为最大500个点 即使是单向 也有500*499/2=12w得边 存双向要25w的边至多 
//3.边权可能大于A 导致结果并不是最小 处理的不够好 只能得90分 最后一个会WA
//4.最终处理  if(A+edge[i].w>A+A) continue;以及 if(line>=1) ans+=A; 就可以AC了 
struct node{
	int u,v,w;
}edge[250000];int ans=0;int id=0;int fa[505];bool visited[505];
void init(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=B;i++) for(int j=1;j<=B;j++){
		int tmp;scanf("%d",&tmp);if(i==j || tmp==0) continue;//边权为0都不建立边 
		if(i<j) edge[++id].u=i,edge[id].v=j,edge[id].w=tmp;
	}
	for(int i=1;i<=505;i++) fa[i]=i;
	fill(visited,visited+505,0);
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
	sort(edge+1,edge+id+1,cmp);int line=0;
	for(int i=1;i<=id;i++){ //id条边 B个点 只要line为B-1条边就可以得到最小生成树了 
		int from=edge[i].u;int to=edge[i].v;
		if(A+edge[i].w>A+A) continue;//避免边权比A还大 这种就不用选了 但是不太对 因为可以连续买 
		if(find(from)!=find(to)) 
			merge(from,to),ans+=edge[i].w,line++;visited[from]=1,visited[to]=1;
		if(line==B-1){
			printf("%d",ans+A);return; 
		}
	}
	//如果还没有结束 说明有的点间的距离是0 这些点需要单独加上
	for(int i=1;i<=B;i++) if(!visited[i]) ans+=A;
	//错因 不能用id判断 有边但是可以不选 因为存在 A+edge[i].w>A+A 应该用line判断 
	if(line>=1) ans+=A; printf("%d",ans); 
}
int main(){
	init();
	Kruskal();
	return 0;
}

