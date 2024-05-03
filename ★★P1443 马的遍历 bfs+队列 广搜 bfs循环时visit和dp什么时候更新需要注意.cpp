#include<bits/stdc++.h>
using namespace std;
//这题应该考虑用的应该是广度搜索 高度越低的应该先被搜索到 这样就可以用visited数组了
#include<bits/stdc++.h>
#define MAXN 404
using namespace std;
int n,m,x,y;
int dp[MAXN][MAXN];
bool visited[MAXN][MAXN];
int xxx[]={0,1,2,1,2,-1,-2,-1,-2};
int yyy[]={0,-2,-1,2,1,2,1,-2,-1};
queue<pair<int,int> >q;
void bfs(){
	q.push(make_pair(x,y));dp[x][y]=0;visited[x][y]=1;//int dis=0;
	while(!q.empty()){
		int x0=q.front().first,y0=q.front().second;q.pop();
		//visited[x0][y0]=1;//dp[x0][y0]=dis;
		for(int i=1;i<=8;i++){ //循环的过程中就必须赋值dp 否则出队列再赋值 数值就不对了 
			int x2=x0+xxx[i];int y2=y0+yyy[i];
			if(x2>n || x2<=0 || y2>m || y2<=0 ||visited[x2][y2]==1) continue;
			visited[x2][y2]=1;dp[x2][y2]=dp[x0][y0]+1;q.push(make_pair(x2,y2));
		}
		//dis++;
	}
} 
void print(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
}
int main(){
	fill(dp[0],dp[0]+MAXN*MAXN,-1);
	scanf("%d%d%d%d",&n,&m,&x,&y);//dp[x][y]=0;
	bfs();
	print();
	return 0;
} 












