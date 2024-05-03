#include<bits/stdc++.h>
#define MAXN 100005
using namespace std;
int fa[MAXN];//数据可以不需要存储
bool visited[MAXN];//用来标记集合是否唯一 
//(题干细节)小错误修正:题目要求任何两个房间有且只有一条路 说明首先路径唯一 其次必须都连通 也就是一个集合
//如果出现了两个甚至多个集合 说明不连通 也不可以 
//(集合是否唯一的判定方法非原创 需要学习)
int find(int x){
	if(fa[x]==x) return x;
	return fa[x]=find(fa[x]);
}
void merge(int u,int v){
	fa[find(u)]=find(v);
}
int main(){
	while(1){
		int flag=1;int set_num=0;//表示当前集合的数量 
		for(int i=1;i<=100000;i++) fa[i]=i;//初始化 
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
		}//本轮数据已经循环完毕 
	}
} 



