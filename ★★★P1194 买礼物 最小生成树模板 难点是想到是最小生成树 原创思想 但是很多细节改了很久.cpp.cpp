#include<bits/stdc++.h>
using namespace std;
int A,B;//B������ ÿ��AԪ 
//���ģ�Ҫ���Կ����� ����⿼����ʵ����С������
//��Kruskal���� ������Ҫ�ҵ���Щû�б����뼯�ϵĵ㵥������ 
//��PrimҲ���� ��visitedҲ�ܷ���ﵽĿ�� 
//1.�ر�O2�Ż� ����������  2.Kruskal����ͼ ���뵥���� ˫��Ҳ�� ����û��Ҫ sort�Ժ���кܶ��ظ��ж� 
//�Լ��㷨����:1.������� Ҫ�ر�02�Ż� 2.edgeҪ���ܴ� һֱ���״� ��Ϊ���500���� ��ʹ�ǵ��� Ҳ��500*499/2=12w�ñ� ��˫��Ҫ25w�ı����� 
//3.��Ȩ���ܴ���A ���½����������С ����Ĳ����� ֻ�ܵ�90�� ���һ����WA
//4.���մ���  if(A+edge[i].w>A+A) continue;�Լ� if(line>=1) ans+=A; �Ϳ���AC�� 
struct node{
	int u,v,w;
}edge[250000];int ans=0;int id=0;int fa[505];bool visited[505];
void init(){
	scanf("%d%d",&A,&B);
	for(int i=1;i<=B;i++) for(int j=1;j<=B;j++){
		int tmp;scanf("%d",&tmp);if(i==j || tmp==0) continue;//��ȨΪ0���������� 
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
	return a.w<b.w;//��С���� 
}
void Kruskal(){
	sort(edge+1,edge+id+1,cmp);int line=0;
	for(int i=1;i<=id;i++){ //id���� B���� ֻҪlineΪB-1���߾Ϳ��Եõ���С�������� 
		int from=edge[i].u;int to=edge[i].v;
		if(A+edge[i].w>A+A) continue;//�����Ȩ��A���� ���־Ͳ���ѡ�� ���ǲ�̫�� ��Ϊ���������� 
		if(find(from)!=find(to)) 
			merge(from,to),ans+=edge[i].w,line++;visited[from]=1,visited[to]=1;
		if(line==B-1){
			printf("%d",ans+A);return; 
		}
	}
	//�����û�н��� ˵���еĵ��ľ�����0 ��Щ����Ҫ��������
	for(int i=1;i<=B;i++) if(!visited[i]) ans+=A;
	//���� ������id�ж� �бߵ��ǿ��Բ�ѡ ��Ϊ���� A+edge[i].w>A+A Ӧ����line�ж� 
	if(line>=1) ans+=A; printf("%d",ans); 
}
int main(){
	init();
	Kruskal();
	return 0;
}

