#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
int n,m;int graph[MAXN][MAXN];bool visited[MAXN][MAXN];int ans=0;
int xx[]={0,-1,1,0,0};
int yy[]={0,0,0,1,-1};
void init(){ //P1451 ��ϸ������
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			//���뷽��1: 
			//char tmp;cin>>tmp;graph[i][j]=tmp-'0';
			//���뷽��2:
			scanf("%1d",&graph[i][j]); 
		}
}
//����1:bfs�����������(����)
queue<pair<int,int> >q;
void bfs(int x,int y){
	q.push(make_pair(x,y));
	while(!q.empty()){
		int tmp_x=q.front().first,tmp_y=q.front().second;visited[tmp_x][tmp_y]=1;
		for(int i=1;i<=4;i++){
			int x0=tmp_x+xx[i];int y0=tmp_y+yy[i];
			if(x0<1 || x0>n || y0<1 || y0>m) continue;
			if(!visited[x0][y0]&&graph[x0][y0]!=0) q.push(make_pair(x0,y0));
		}
		q.pop(); 
	}
}
//����2:dfs�����������
void dfs(int x0,int y0){
	if(x0<1 || x0>n || y0<1 || y0>m || visited[x0][y0]==true || graph[x0][y0]==0) return;
	visited[x0][y0]=1;for(int i=1;i<=4;i++) dfs(x0+xx[i],y0+yy[i]);
} 
int main(){
	init();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) 
			//��������汾 
			//if(graph[i][j]!=0 && !visited[i][j]) bfs(i,j),ans++;
			//��������汾 
			if(graph[i][j]!=0 && !visited[i][j]) dfs(i,j),ans++;
	printf("%d",ans);
	return 0;
}



