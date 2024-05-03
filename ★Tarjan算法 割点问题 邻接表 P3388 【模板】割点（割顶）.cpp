#include<bits/stdc++.h>
#define MAXV 20005
#define MAXN 100005
using namespace std;
vector<int>G[MAXV];
int n,m,Root;
int dfn[MAXV],low[MAXV];int indexs=0;
int flag[MAXV];int ans=0;//节点个数
void Tarjan(int id){
	dfn[id]=++indexs;low[id]=dfn[id];int son=0;//分支 一个分支不能算是割点 
	for(int i=0;i<G[id].size();i++){
		int child = G[id][i];
		if(!dfn[child]){ //没有被访问过 则是树边 可用其low更新自己 
			Tarjan(child);low[id]=min(low[id],low[child]);
			if(id==Root) son++;
			if(dfn[id]<=low[child] && id!=Root) ans+=!flag[id],flag[id]=1;
		}else low[id]=min(low[id],dfn[child]);  //被访问过说明是返祖边 用dfn更新 
	}
	if(son>=2 && id==Root) ans+=!flag[id],flag[id]=1;
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);
		G[tmp1].push_back(tmp2);G[tmp2].push_back(tmp1);
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) Root=i,Tarjan(i);
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) if(flag[i]) printf("%d ",i);
	return 0;
}








