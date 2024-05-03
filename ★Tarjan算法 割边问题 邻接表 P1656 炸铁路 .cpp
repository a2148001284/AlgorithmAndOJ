#include<bits/stdc++.h>
#define MAXV 155
#define MAXN 5005 
using namespace std;
vector<int>G[MAXV];int n,m; //邻接表存图 
int dfn[MAXV],low[MAXV];int indexs=0;int ans=0;
struct Edge{ //答案的边 后续需要排序 
	int from;int to;
}edge[MAXV];
void add(int x,int y){
	edge[ans].from=min(x,y);
	edge[ans++].to=max(x,y);
} 
void Tarjan(int cur,int fa){//cur为当前节点 fa为父节点 
	int child;dfn[cur]=++indexs;low[cur]=dfn[cur];bool flag=false; 
	for(int i=0;i<G[cur].size();i++){ //遍历所有出点 
		child=G[cur][i];
		if(dfn[child]){//该节点已经被访问过 
			if(child==fa && !flag) flag=true;//除第一次以外访问就需要更新 
			else low[cur]=min(low[cur],dfn[child]);
		}
		if(!dfn[child]){ //该节点没有被访问过 
			Tarjan(child,cur);low[cur]=min(low[cur],low[child]);
			if(dfn[cur]<low[child]) add(cur,child); //符合条件的割边
		}
	}
}
bool cmp(Edge a,Edge b){
	if(a.from!=b.from) return a.from<b.from;
	return a.to<b.to; 
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmp1,tmp2;scanf("%d %d",&tmp1,&tmp2);
		G[tmp1].push_back(tmp2);G[tmp2].push_back(tmp1);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,i);//图可能不连通 到自己没有问题
	sort(edge,edge+ans,cmp);
	for(int i=0;i<ans;i++)
		printf("%d %d\n",edge[i].from,edge[i].to);
	return 0;
}
