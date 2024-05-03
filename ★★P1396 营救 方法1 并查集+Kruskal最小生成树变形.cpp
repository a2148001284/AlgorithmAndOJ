#include<bits/stdc++.h>
using namespace std;
//ӵ���ȵ����ֵ��С
//����1: Kruskal��С������+���鼯+��ʽ�洢 
//����ȥ������ȥ�Ƚ� �ⲻ�����·�� �����Ǳߵĺ���С ���Ǳ���С+��ͨ

//����2:Dijkstra+���Ż�+��ʽǰ���� ���� 
//̰�Ĳ���:dis����洢��ÿ���ڵ�����ӵ���� ��С������ÿ��ѡ���ӵ������С�Ľ�����չ����(���Prim�㷨)

//����չʾ����1
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
	for(int i=1;i<=m;i++){//���: i<=n n��m����Ū���� 
		int x1=edge[i].u;int y1=edge[i].v;
		if(x1!=y1) merge(x1,y1);
		if(find(s)==find(t)){ //Ŀ����Ѿ���ͨ �ﵽ���� 
			printf("%d",edge[i].w);return;
		}
	}
}
bool cmp(node a,node b){ //��С�������� 
	return a.w<b.w;
}
int main(){
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		edge[i].u=a;edge[i].v=b;edge[i].w=c;fa[i]=i; 
	}
	sort(edge+1,edge+m+1,cmp);//����sort(edge,edge+MAXN,cmp); ��Ӧ��д��MAXN  edge[1]->edge[m] Ӧ��+1��+m+1 ע����m������n �ҿ�ͷ��+1 
	Kruskal();
	return 0;
} 




