#include<bits/stdc++.h>
using namespace std;
int totalV;int n;int weight[31];int targetV; 
void dfs(int now,int leftV){//now��ʾ�����ǵڼ�����Ʒ leftV������ʣ���ٿռ� 
	if(now>n || leftV<0) return;
	targetV = min(targetV,leftV);
	dfs(now+1,leftV);
	dfs(now+1,leftV-weight[now+1]);
}
int main(){
	scanf("%d",&totalV);scanf("%d",&n);targetV=totalV;
	for(int i=1;i<=n;i++) scanf("%d",&weight[i]);
	dfs(1,totalV);
	dfs(1,totalV-weight[1]);
	printf("%d",targetV);
	return 0;
}








