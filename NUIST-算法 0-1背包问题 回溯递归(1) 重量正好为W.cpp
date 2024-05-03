#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
bool visited[MAXV];//表明第i个物品有没有被选择
int maxv=0;//最优解的总价值 
int maxw=0;int totalweight=0;//右剪枝要用 
/**
4 6
5 3 2 1
4 4 3 1
==>8
 **/
void init(){
	fill(visited,visited+MAXV,0);
	cin>>n;cin>>Bag_Weight;
	for(int i=1;i<=n;i++){
		cin>>weight[i];totalweight+=weight[i];
	}
	for(int i=1;i<=n;i++) cin>>value[i];
}

//1.不含优化的dfs回溯递归的算法 (重量刚好为W的算法)
void dfs(int i,int tw,int tv,int op[]){ //tw为放入的总重量 tv为放入的总价值 i为第i层 
	if(i>n){
		if(tw==Bag_Weight && tv>maxv){
			maxv=tv;maxw=tw;for(int j=1;j<=n;j++) visited[j]=op[j];
		}
	} else{
		op[i]=1;dfs(i+1,tw+weight[i],tv+value[i],op);
		op[i]=0;dfs(i+1,tw,tv,op);
	}
} 
//2.含有优化 左剪枝和右剪枝  (重量刚好为W的算法)
void dfs2(int i,int tw,int tv,int op[],int rw){ //rw为当前行及以后所有物品的重量 右剪枝判断需要 
	if(i>n){
		if(tw==Bag_Weight &&tv>maxv){
			maxv=tv;maxw=tw;for(int i=1;i<=n;i++) visited[i]=op[i];
		}
	} else{
		if(tw+weight[i]<=Bag_Weight) { //左剪枝 如果选中后重量已经超过可容纳的值 就不用继续讨论了 
			op[i]=1;dfs2(i+1,tw+weight[i],tv+value[i],op,rw-weight[i]);
		}
		if(tw+rw-weight[i]>=Bag_Weight){//右剪枝 不选当前物品后 如果把后续所有物品都选上 是可以超过最大重量的 否则就不符合刚好为W 可以剪枝 
			op[i]=0;dfs2(i+1,tw,tv,op,rw-weight[i]); 
		}
	}
}

int main(){
	//1.重量刚好为W的算法
	init();int tmp[MAXV];fill(tmp,tmp+MAXV,0);
	dfs(1,0,0,tmp); //0.8391s
	dfs2(1,0,0,tmp,totalweight);  //0.661s  剪枝优化有效 	
	cout<<maxv<<endl;
	return 0;
}






