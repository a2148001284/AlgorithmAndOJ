#include<bits/stdc++.h>
using namespace std;
int n;int suandu[11];int kudu[11];
bool visited[11];int final_ans=INT_MAX;
//原创 一遍过 
void dfs(int ans,int targ,int total_suandu,int total_kudu,int flag){
	if(targ==n+1){
		if(flag==1) final_ans=min(final_ans,ans);return;
	}
	//不选中时 
	dfs(ans,targ+1,total_suandu,total_kudu,flag);
	//选中时
	total_suandu*=suandu[targ];
	total_kudu+=kudu[targ];flag=1;
	ans=min(ans,abs(total_kudu-total_suandu));
	dfs(ans,targ+1,total_suandu,total_kudu,flag); 
}
int main(){
	fill(visited,visited+11,0);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d%d",&suandu[i],&kudu[i]);
	dfs(INT_MAX,1,1,0,0);
	printf("%d",final_ans);
	return 0;
}



