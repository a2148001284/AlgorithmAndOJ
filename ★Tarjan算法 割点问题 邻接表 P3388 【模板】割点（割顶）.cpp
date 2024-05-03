#include<bits/stdc++.h>
#define MAXV 20005
#define MAXN 100005
using namespace std;
vector<int>G[MAXV];
int n,m,Root;
int dfn[MAXV],low[MAXV];int indexs=0;
int flag[MAXV];int ans=0;//�ڵ����
void Tarjan(int id){
	dfn[id]=++indexs;low[id]=dfn[id];int son=0;//��֧ һ����֧�������Ǹ�� 
	for(int i=0;i<G[id].size();i++){
		int child = G[id][i];
		if(!dfn[child]){ //û�б����ʹ� �������� ������low�����Լ� 
			Tarjan(child);low[id]=min(low[id],low[child]);
			if(id==Root) son++;
			if(dfn[id]<=low[child] && id!=Root) ans+=!flag[id],flag[id]=1;
		}else low[id]=min(low[id],dfn[child]);  //�����ʹ�˵���Ƿ���� ��dfn���� 
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








