#include<bits/stdc++.h>
#define MAXN 105
#define INF INT_MAX  //��Ϊ�õ�INT_MAX ����һ�������κμӷ� �ͻᱬint ����Ҫ��long long 
//const int INF=0x3f3f3f3f;  //�������Ϊ��� �Ϳ�����int�͹��� 
using namespace std;
//Flyod�㷨���� �����ӱ� ���ÿ�����Ӷ���һ��Flyod ���Ӷ�̫�ߡ�
//������ӱߺ�����֮������·�Ѿ��������ı߳���ҪС�� ��û��Ҫ������ ����Ӱ�����ߵ����dis
int n,m;long long dis[MAXN][MAXN];
/*Flyod�㷨�ľ��� 
for (k=0;k<g.vexnum;k++){
	for (i=0;i<g.vexnum;i++)
        for (j=0;j<g.vexnum;j++)
            if (A[i][j]>A[i][k]+A[k][j]){
				A[i][j]=A[i][k]+A[k][j];
               	path[i][j]=path[k][j];	
				//�޸����·�� path[i][j]��ʾi��j֮ǰҪ�������м�ڵ� Ҳ��д��path[i][j]=k 
            }
*/ 
void Flyod(int x,int y){//�൱��flyod�㷨�������ѭ�� ֻѭ��x��y������ 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][x]+dis[x][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][y]+dis[y][j]); 
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) if(i!=j) dis[i][j]=INF;
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		if(a==0) printf("%lld\n",dis[b][c]==INF?-1:dis[b][c]);
		else{
			long long d;scanf("%lld",&d);
			if(dis[b][c]>d){dis[b][c]=dis[c][b]=d;Flyod(b,c);}//�и��µı�Ҫ ȥflyod����һ�θ��� 
		}
	}
	return 0; 
} 






