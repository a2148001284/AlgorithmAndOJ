#include<bits/stdc++.h>
using namespace std;
int n;bool visited[11];int path[11];//path��¼·�� 
void print(){
	for(int i=1;i<=n;i++) printf("%5d",path[i]);//����5������ ����5λ���Ҷ������ 
	cout<<endl;
}
void dfs(int counts){ //counts������ǰ�Ѿ������˶��ٵ��� 
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








