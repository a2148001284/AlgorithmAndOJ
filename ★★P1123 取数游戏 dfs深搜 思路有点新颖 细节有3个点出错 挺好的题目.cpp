#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>//fill使用的头文件 
using namespace std;
//由于每一个点确定后 周围不可以再被选择 会影响下一步 所以不可用动态规划/贪心
//dfs搜索 逐行搜索 用数组标记这个点是否还可以被取
int n,m;int number[10][10];int t;int chos[10][10];//开大点 赋值的时候避免出现下标越界的问题要处理 
int maxstarg=0;int tmpmax=0;
int xx[9]={0,-1,-1,-1,0,0,1,1,1};//错因2 id=0没处理 导致数组越界 
int yy[9]={0,1,0,-1,1,-1,1,0,-1}; 
//值得学习:按照循环每个点来搜 都分选和不选 然后回溯 
void dfs(int x,int y){
	//if(x<1 || y<1 || y>n) return;//错因1:有一个x==n+1 两个条件冲突了 且越界没必要存在,不会往回搜 按照要求搜  
	if(x==n+1){
		maxstarg=max(maxstarg,tmpmax);return;
	} //终止条件 
	if(y==m) dfs(x+1,1); else dfs(x,y+1);//表示当前点不选 直接搜下一个 
	if(chos[x][y]==0){ //当前点可以选 则选取 
		for(int i=1;i<=8;i++) chos[x+xx[i]][y+yy[i]]++;//标记周围的点 不可再访问了 
		tmpmax+=number[x][y];if(y==m) dfs(x+1,1); else dfs(x,y+1); 
		for(int i=1;i<=8;i++) chos[x+xx[i]][y+yy[i]]--;tmpmax-=number[x][y];//回溯 
		//错误3:chos不能用bool表示 当前是否可以访问 因为在深搜的时候涉及到很多点重复访问,只有回溯到真的减为0才是真的可以访问 
	}
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);fill(chos[0],chos[0]+10*10,0);tmpmax=0;maxstarg=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&number[i][j]);dfs(1,1);
		printf("%d\n",maxstarg);
	}
	return 0;
}
