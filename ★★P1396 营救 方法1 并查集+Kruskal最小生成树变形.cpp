#include<bits/stdc++.h>
using namespace std;
//拥挤度的最大值最小
//方法1: Kruskal最小生成树+并查集+链式存储 
//无需去遍历再去比较 这不是最短路径 并不是边的和最小 而是边最小+连通

//方法2:Dijkstra+堆优化+链式前向星 变种 
//贪心策略:dis数组存储到每个节点的最大拥挤度 用小根堆来每次选最大拥挤度最小的进行拓展即可(类比Prim算法)

//这里展示方法1
#define MAXN 20005
int n,m,s,t;
struct node{
	int u,v,w;
}edge[MAXN];int fa[MAXN];
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
void Kruskal(){
	for(int i=1;i<=m;i++){//错点: i<=n n和m总是弄混淆 
		int x1=edge[i].u;int y1=edge[i].v;
		if(x1!=y1) merge(x1,y1);
		if(find(s)==find(t)){ //目标点已经连通 达到最优 
			printf("%d",edge[i].w);return;
		}
	}
}
bool cmp(node a,node b){ //从小到大排序 
	return a.w<b.w;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		edge[i].u=a;edge[i].v=b;edge[i].w=c;fa[i]=i; 
	}
	sort(edge+1,edge+m+1,cmp);//错因：sort(edge,edge+MAXN,cmp); 不应该写到MAXN  edge[1]->edge[m] 应该+1到+m+1 注意是m而不是n 且开头是+1 
	Kruskal();
	return 0;
} 




