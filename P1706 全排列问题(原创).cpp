#include<bits/stdc++.h>
using namespace std;
int n;bool visited[11];int path[11];//path记录路径 
void print(){
	for(int i=1;i<=n;i++) printf("%5d",path[i]);//保留5个场宽 不足5位就右对齐输出 
	cout<<endl;
}
void dfs(int counts){ //counts表明当前已经访问了多少点了 
	if(counts==n){print(); return;}
	for(int i=1;i<=n;i++)
		if(!visited[i]){
			visited[i]=1;path[counts+1]=i;
			dfs(counts+1);visited[i]=0;
		}
}
int main(){
	scanf("%d",&n);
	dfs(0);
	return 0;
}








