#include<bits/stdc++.h>
using namespace std;
#define MAXV 100
#define INF 0x3f3f3f3f
typedef char VertexType;
typedef int EdgeType;
typedef struct{
	VertexType Vex[MAXV];
	EdgeType Edge[MAXV][MAXV];
	int vexnum,arcnum; //顶点数 弧数 
}MGraph;

void Dijkstra(MGraph g,int v)		//Dijkstra算法
{  int dist[MAXV],path[MAXV];   //dist存距离 path存该点上一个点
   int S[MAXV];  //用来存储已经完成的节点 N+  visited
   int mindis,i,j,u;
   for (i=0;i<g.vexnum;i++)
   {  dist[i]=g.Edge[v][i];		//距离初始化
      S[i]=0;				//S[]置空
      if (g.Edge[v][i]<INF)		//路径初始化
        path[i]=v;	//顶点v到顶点i有边时，置顶点i的前一个顶点为v
      else
        path[i]=-1;	//顶点v到顶点i没边时，置顶点i的前一个顶点为-1
   }
   S[v]=1;path[v]=0;			//源点编号v放入s中
	for (i=0;i<g.vexnum;i++) //i控制次数 循环直到所有顶点的最短路径都求出
   {  mindis=INF;		//mindis求最小路径长度
      for (j=0;j<g.vexnum;j++)	//选取不在s中且具有最小距离的顶点u
         if (S[j]==0 && dist[j]<mindis) 
         {  u=j;
            mindis=dist[j];
         }
      S[u]=1;				//顶点u加入s中
      for (j=0;j<g.vexnum;j++)		//修改不在S中的顶点的距离
        if (S[j]==0)  //找到没有加入其中的点j
           if (g.Edge[u][j]<INF && dist[u]+g.Edge[u][j]<dist[j])
           {  dist[j]=dist[u]+g.Edge[u][j];
              path[j]=u;  //j的上一个节点是u
           }
   }
   //Dispath1(g,dist,path,S,v);	输出最短路径
}

void Floyd(MGraph g){
	int A[MAXV][MAXV],path[MAXV][MAXV]; //A存最短路径 path存上一个点 
   	int i,j,k;
   	for (i=0;i<g.vexnum;i++)  //初始化A和path
     	for (j=0;j<g.vexnum;j++) {
		 	A[i][j]=g.Edge[i][j];
        	if (i!=j && g.Edge[i][j]<INF)  path[i][j]=i;		//顶点i到j有边时 上一个是i
        	else path[i][j]=-1;		//顶点i到j没有边时
    }
	for (k=0;k<g.vexnum;k++){
		for (i=0;i<g.vexnum;i++)
	        for (j=0;j<g.vexnum;j++)
	            if (A[i][j]>A[i][k]+A[k][j]){
					A[i][j]=A[i][k]+A[k][j];
	               	path[i][j]=path[k][j];	//修改最短路径
	            }
	}
	//Dispath2(g,A,path);			//输出最短路径
}

int main(){
	
}
