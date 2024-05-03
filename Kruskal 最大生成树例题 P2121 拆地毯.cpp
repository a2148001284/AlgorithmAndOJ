#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
//Kruskal����������㷨 ���鼯+��ʽ�洢
struct node{
	int u,v,w;
}edge[MAXN];int fa[MAXN];
int n,m,k;

void init(){
	scanf("%d %d %d",&n,&m,&k);
	for(int i=0;i<m;i++){
		int a,b,c;scanf("%d %d %d",&a,&b,&c);
		edge[i].u=a;edge[i].v=b;edge[i].w=c;//ֻ��һ������ ����ͼ ����νu��v 
	}
	for(int i=1;i<=n;i++) fa[i]=i;
}
int find(int x){
	if(x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
//void merge(int x,int y){
//	fa[find(x)]=find(y);
//}
bool cmp(node a,node b){
	return a.w>b.w;
}
void Kruskal(){
	sort(edge,edge+m,cmp); //�Ӵ�С�������еı� 
	int ans=0;int flag=0; 
	for(int i=0;i<m;i++){
		int u=edge[i].u,v=edge[i].v,w=edge[i].w;
		int fu=find(u);int fv=find(v);
		if(fu==fv) continue; //ͬһ���ڵ� �Ѿ��ڼ����� 
		ans+=w;fa[fu]=fv;flag++;
		if(flag==k){ //����:i==k-1 ��һ��ǰ��ı߶��ӽ�ȥ�� ֻ�����ӵĲſ���ͳ�� 
			printf("%d",ans);break;
		}
	}
}
int main(){
	init();
	Kruskal();
	return 0;
}
 
 










