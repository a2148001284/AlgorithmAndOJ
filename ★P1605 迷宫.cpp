#include<bits/stdc++.h>
#define MAXV 6
using namespace std;
int n,m,t;int sx,sy,fx,fy;
int visited[MAXV][MAXV];
//struct node{
//	int x0;int y0;
//}b[11];
int ans=0;
//int IsOk(int x,int y){
//	for(int i=1;i<=t;i++){
//		if(b[i].x0==x && b[i].y0==y) return 1;
//	}
//	return 0;
//}
void dfs(int x,int y){
	if(visited[x][y]==1) return;
	if(x==fx && y==fy){ans++;return;}
	//if(IsOk(x,y)) return;
	if(1<=x && x<=n && 1<=y && y<=m){
		visited[x][y]=1;
		dfs(x+1,y);
		dfs(x-1,y);
		dfs(x,y+1);
		dfs(x,y-1);
		visited[x][y]=0;
	}else return;
}
int main(){
	scanf("%d",&n);scanf("%d",&m);scanf("%d",&t);
	scanf("%d",&sx);scanf("%d",&sy);scanf("%d",&fx);scanf("%d",&fy);
	fill(visited[0],visited[0]+MAXV*MAXV,0);
	for(int i=1;i<=t;i++){
		int tmp1,tmp2;scanf("%d %d",&tmp1,&tmp2);
		//b[i].x0=tmp1;b[i].y0=tmp2;
		visited[tmp1][tmp2]=1;
	}
	dfs(sx,sy);
	printf("%d",ans);
	return 0;
}




