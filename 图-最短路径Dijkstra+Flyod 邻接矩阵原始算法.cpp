#include<bits/stdc++.h>
using namespace std;
#define MAXV 100
#define INF 0x3f3f3f3f
typedef char VertexType;
typedef int EdgeType;
typedef struct{
	VertexType Vex[MAXV];
	EdgeType Edge[MAXV][MAXV];
	int vexnum,arcnum; //������ ���� 
}MGraph;

void Dijkstra(MGraph g,int v)		//Dijkstra�㷨
{  int dist[MAXV],path[MAXV];   //dist����� path��õ���һ����
   int S[MAXV];  //�����洢�Ѿ���ɵĽڵ� N+  visited
   int mindis,i,j,u;
   for (i=0;i<g.vexnum;i++)
   {  dist[i]=g.Edge[v][i];		//�����ʼ��
      S[i]=0;				//S[]�ÿ�
      if (g.Edge[v][i]<INF)		//·����ʼ��
        path[i]=v;	//����v������i�б�ʱ���ö���i��ǰһ������Ϊv
      else
        path[i]=-1;	//����v������iû��ʱ���ö���i��ǰһ������Ϊ-1
   }
   S[v]=1;path[v]=0;			//Դ����v����s��
	for (i=0;i<g.vexnum;i++) //i���ƴ��� ѭ��ֱ�����ж�������·�������
   {  mindis=INF;		//mindis����С·������
      for (j=0;j<g.vexnum;j++)	//ѡȡ����s���Ҿ�����С����Ķ���u
         if (S[j]==0 && dist[j]<mindis) 
         {  u=j;
            mindis=dist[j];
         }
      S[u]=1;				//����u����s��
      for (j=0;j<g.vexnum;j++)		//�޸Ĳ���S�еĶ���ľ���
        if (S[j]==0)  //�ҵ�û�м������еĵ�j
           if (g.Edge[u][j]<INF && dist[u]+g.Edge[u][j]<dist[j])
           {  dist[j]=dist[u]+g.Edge[u][j];
              path[j]=u;  //j����һ���ڵ���u
           }
   }
   //Dispath1(g,dist,path,S,v);	������·��
}

void Floyd(MGraph g){
	int A[MAXV][MAXV],path[MAXV][MAXV]; //A�����·�� path����һ���� 
   	int i,j,k;
   	for (i=0;i<g.vexnum;i++)  //��ʼ��A��path
     	for (j=0;j<g.vexnum;j++) {
		 	A[i][j]=g.Edge[i][j];
        	if (i!=j && g.Edge[i][j]<INF)  path[i][j]=i;		//����i��j�б�ʱ ��һ����i
        	else path[i][j]=-1;		//����i��jû�б�ʱ
    }
	for (k=0;k<g.vexnum;k++){
		for (i=0;i<g.vexnum;i++)
	        for (j=0;j<g.vexnum;j++)
	            if (A[i][j]>A[i][k]+A[k][j]){
					A[i][j]=A[i][k]+A[k][j];
	               	path[i][j]=path[k][j];	//�޸����·��
	            }
	}
	//Dispath2(g,A,path);			//������·��
}

int main(){
	
}
