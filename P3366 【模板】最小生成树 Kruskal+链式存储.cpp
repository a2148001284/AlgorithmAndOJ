#include<iostream>
#include<queue>
#include<limits.h> 
#include<algorithm>
using namespace std;
#define MAXV 100000
#define INF INT_MAX
struct node{
	int u; 
	int v; 
	int w;  
}edge[5*MAXV];
int fa[MAXV];int tol=0;//�������� 
bool cmp(node a,node b){
	return a.w<b.w;
}
int find(int x){
	while(x!=fa[x]) x=fa[x]=fa[fa[x]];
	return x; 
}
void Kruskal(int n,int m){
	int ans=0;//��ĿҪ�� 
	sort(edge,edge+m,cmp);//�߰���Ȩֵ����
	for(int i=0;i<m;i++){
		int e_to = find(edge[i].u);int e_w = find(edge[i].v);
		if(e_to == e_w) continue; //˵����������ͨ �����߲���Ҫ��
		ans+=edge[i].w;
		fa[e_w]=e_to;
		if(++tol==n-1){
			cout<<ans; return;
		}
	} 
	cout<<"orz";
}
int main(){
	int n,m;cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y,z;cin>>x>>y>>z;
		edge[i].u=x;edge[i].v=y;edge[i].w=z;
	}
	//��ʼ�����鼯��fa
	for(int i=1;i<=n;i++) fa[i]=i; 
	Kruskal(n,m);
	return 0;
}






