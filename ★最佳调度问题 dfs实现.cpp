#include<bits/stdc++.h>
using namespace std;
//最佳调度问题
int n,k;//n为任务数量 k为机器的数量
int x[100];//机器
int x1[100];//作业
int mintime=INT_MAX;
/**
7 3
2 14 4 16 6 5 3
 **/
void dfs(int h){//h针对的第几个任务 
	if(h>n){
		int tmp=0;
		for(int i=1;i<=k;i++){
			if(x[i]>tmp) tmp=x[i];//找到所有机器中用时最多的机器 
		}
		mintime=min(mintime,tmp);
	}else{
		for(int i=1;i<=k;i++){
			x[i]+=x1[h];
			dfs(h+1);
			x[i]-=x1[h];
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>x1[i];dfs(1);
	cout<<mintime;return 0;
} 
