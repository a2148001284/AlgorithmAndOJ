#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<queue>
//#define inf 0x3f3f3f3f
using namespace std;
int n,m,x,y;
int pan[405][405];
int xx[]={0,-1,-2,-1,-2,1,2,1,2};
int yy[]={0,2,1,-2,-1,2,1,-2,-1};
queue<pair<int,int> >q;
//区分数学里(x,y)坐标 和数组中的[x][y]
void bfs(){
	pan[x][y]=0;q.push(make_pair(x,y));
	while(!q.empty()){
		int x0=q.front().first,y0=q.front().second;q.pop();
		if(x0<1||x0>n||y0<1||y0>m) continue;//错因 改半天 因为n和m顺序写反了可还行 
		for(int i=1;i<=8;i++){
			if(pan[x0+xx[i]][y0+yy[i]]==-1)
				pan[x0+xx[i]][y0+yy[i]]=pan[x0][y0]+1,q.push(make_pair(x0+xx[i],y0+yy[i]));	
		}
	}
} 
int main(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	fill(pan[0],pan[0]+405*405,-1);
	bfs();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) 
		printf("%d ",pan[i][j]);
		printf("\n"); 
	}
	return 0;
}
