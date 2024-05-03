#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int T,n,m;int a[8][8];int con[8][8];//用于统计位置的空闲 
int maxs=0;int tmpmax=0;
int xx[]={0,-1,-1,-1,0,0,1,1,1};
int yy[]={0,1,0,-1,1,-1,1,0,-1};
void dfs(int x,int y){
	if(x>n){maxs=max(maxs,tmpmax);return;}
	if(y==m) dfs(x+1,1); else dfs(x,y+1);
	if(con[x][y]==0){
		for(int i=1;i<=8;i++) con[x+xx[i]][y+yy[i]]++;
		tmpmax+=a[x][y];if(y==m) dfs(x+1,1); else dfs(x,y+1);
		for(int i=1;i<=8;i++) con[x+xx[i]][y+yy[i]]--;tmpmax-=a[x][y];//回溯 
	}
}
int main(){
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
		fill(con[0],con[0]+8*8,0);tmpmax=0,maxs=0;
		dfs(1,1);printf("%d\n",maxs);
	}
	return 0;
}
