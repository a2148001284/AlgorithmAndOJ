#include<bits/stdc++.h>
#define MAXN 105
#define INF INT_MAX  //因为用的INT_MAX 所以一旦出现任何加法 就会爆int 所以要用long long 
//const int INF=0x3f3f3f3f;  //如果定义为这个 就可以用int就够了 
using namespace std;
//Flyod算法变形 会增加边 如果每次增加都跑一轮Flyod 复杂度太高。
//如果增加边后，两点之间的最短路已经比新增的边长度要小了 就没必要更新了 不会影响两者的最短dis
int n,m;long long dis[MAXN][MAXN];
/*Flyod算法的精髓 
for (k=0;k<g.vexnum;k++){
	for (i=0;i<g.vexnum;i++)
        for (j=0;j<g.vexnum;j++)
            if (A[i][j]>A[i][k]+A[k][j]){
				A[i][j]=A[i][k]+A[k][j];
               	path[i][j]=path[k][j];	
				//修改最短路径 path[i][j]表示i到j之前要经过的中间节点 也可写成path[i][j]=k 
            }
*/ 
void Flyod(int x,int y){//相当于flyod算法的最外层循环 只循环x和y两个点 
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
			if(dis[b][c]>d){dis[b][c]=dis[c][b]=d;Flyod(b,c);}//有更新的必要 去flyod进行一次更新 
		}
	}
	return 0; 
} 






