#include<bits/stdc++.h>
using namespace std;
int n,k;int number[25];int ans=0;
bool JudgeSushu(int x){
		int j;
		for(j=2;j<=sqrt(x);j++){
			if(x%j==0) return 0;
		}
		if(j>sqrt(x)) return 1;
}
void dfs(int has_chos,int flag,int sums){
	if(has_chos>k || flag>n) return;
	if(has_chos==k && flag<=n){
		if(JudgeSushu(sums)) ans++;
		return;
	}
	dfs(has_chos+1,flag+1,sums+number[flag+1]);
	dfs(has_chos,flag+1,sums);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&number[i]);
	dfs(0,0,0);
	printf("%d",ans);
	return 0;
}



