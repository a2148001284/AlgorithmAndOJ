#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int fa[MAXN];//���ݿ��Բ���Ҫ�洢
bool visited[MAXN];//������Ǽ����Ƿ�Ψһ 
//(���ϸ��)С��������:��ĿҪ���κ�������������ֻ��һ��· ˵������·��Ψһ ��α��붼��ͨ Ҳ����һ������
//������������������������ ˵������ͨ Ҳ������ 
//(�����Ƿ�Ψһ���ж�������ԭ�� ��Ҫѧϰ)
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
int main(){
	while(1){
		int flag=1;int set_num=0;//��ʾ��ǰ���ϵ����� 
		for(int i=1;i<=100000;i++) fa[i]=i;//��ʼ�� 
		fill(visited,visited+MAXN,0); 
		while(1){
			int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);
			if(tmp1==-1 && tmp2==-1){return 0;}
			if(tmp1==0 && tmp2==0){
				if(flag==1 && set_num==1) printf("1\n");
				else if(flag==1 && set_num!=1) printf("0\n");
				break;
			}
			if(flag){
				if(!visited[tmp1]) set_num++;if(!visited[tmp2]) set_num++;
				visited[tmp1]=1;visited[tmp2]=1;
				if(find(tmp1)!=find(tmp2)) {merge(tmp1,tmp2);set_num--;}
				else{ printf("0\n");flag=0; }
			}
		}//���������Ѿ�ѭ����� 
	}
} 



