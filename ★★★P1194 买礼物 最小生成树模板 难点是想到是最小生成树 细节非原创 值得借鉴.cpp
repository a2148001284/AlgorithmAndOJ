#include<bits/stdc++.h>
using namespace std;
int A,B;//B������ ÿ��AԪ 
//1.�ر�O2�Ż� ����������  2.Kruskal����ͼ ���뵥���� ˫��Ҳ�� ����û��Ҫ sort�Ժ���кܶ��ظ��ж� 
//���ÿ���ڵ��һ��0���ýڵ�ı� ��ȨֵΪA ���������Ȩ����A �������ȿ���A�������ֵ�ӷ� 
struct node{
	int u,v,w;
}edge[250000];int ans=0;int id=0;int fa[505];//bool visited[505];
void init(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=B;i++) for(int j=1;j<=B;j++){
		int tmp;scanf("%d",&tmp);if(i==j || tmp==0) continue;//��ȨΪ0���������� 
		if(i<j) edge[++id].u=i,edge[id].v=j,edge[id].w=tmp;
	}
	for(int i=0;i<=505;i++) fa[i]=i;
	//fill(visited,visited+505,0);
	for(int i=1;i<=B;i++) edge[++id].u=0,edge[id].v=i,edge[id].w=A;//�� 
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
bool cmp(node a,node b){
	return a.w<b.w;//��С���� 
}
void Kruskal(){
	sort(edge+1,edge+id+1,cmp);int cnt=1;
	for(int i=1;i<=id&&cnt<=B;i++){ //id���� B���� ֻҪlineΪB-1���߾Ϳ��Եõ���С�������� 
		int from=edge[i].u;int to=edge[i].v;
		//if(A+edge[i].w>A+A) break;//�����Ȩ��A���� ���־Ͳ���ѡ�� ���ǲ�̫�� ��Ϊ���������� 
		if(find(from)!=find(to)) 
			merge(from,to),ans+=edge[i].w,cnt++;//visited[from]=1,visited[to]=1;
	}
	//�����û�н��� ˵���еĵ��ľ�����0 ��Щ����Ҫ��������
//	for(int i=1;i<=B;i++) if(!visited[i]) ans+=A;
//	if(id>=1) ans+=A; printf("%d",ans); 
}
int main(){
	init();
	Kruskal();printf("%d",ans);
	return 0;
}


