#include<bits/stdc++.h>
#define MAXV 155
#define MAXN 5005 
using namespace std;
vector<int>G[MAXV];int n,m; //�ڽӱ��ͼ 
int dfn[MAXV],low[MAXV];int indexs=0;int ans=0;
struct Edge{ //�𰸵ı� ������Ҫ���� 
	int from;int to;
}edge[MAXV];
void add(int x,int y){
	edge[ans].from=min(x,y);
	edge[ans++].to=max(x,y);
} 
void Tarjan(int cur,int fa){//curΪ��ǰ�ڵ� faΪ���ڵ� 
	int child;dfn[cur]=++indexs;low[cur]=dfn[cur];bool flag=false; 
	for(int i=0;i<G[cur].size();i++){ //�������г��� 
		child=G[cur][i];
		if(dfn[child]){//�ýڵ��Ѿ������ʹ� 
			if(child==fa && !flag) flag=true;//����һ��������ʾ���Ҫ���� 
			else low[cur]=min(low[cur],dfn[child]);
		}
		if(!dfn[child]){ //�ýڵ�û�б����ʹ� 
			Tarjan(child,cur);low[cur]=min(low[cur],low[child]);
			if(dfn[cur]<low[child]) add(cur,child); //���������ĸ��
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
	for(int i=1;i<=n;i++) if(!dfn[i]) Tarjan(i,i);//ͼ���ܲ���ͨ ���Լ�û������
	sort(edge,edge+ans,cmp);
	for(int i=0;i<ans;i++)
		printf("%d %d\n",edge[i].from,edge[i].to);
	return 0;
}
