#include<bits/stdc++.h>
#define MAXN 1000
#define INT INT_MAX
using namespace std;
int n=3,W=30;
int w[]={0,16,15,15};
int v[]={0,45,25,25};
int maxv=-INT;bool visited[MAXN];int counts=0;//序号控制变量 
struct node{
	int id;
	int height;//节点的层次 
	int weight;//当前节点的总重量 
	int value;//当前节点的总价值 
	int x[MAXN];//当前节点包含的解向量
	double ub;//价值上界 
	friend bool operator <(node a,node b){
		return a.ub<b.ub;//优先选择价值上界最大的 可以更好的剪枝 
	}
};
void bound(node &e){ //由于求最大值 所以目标是求上界 可以用于剪枝 
	int i=e.id+1;int sumw=e.weight;//已装入的总重量 
	double sumv=e.value;//已装入的总价值
	while((sumw+w[i]<=W)&&i<=n){
		sumw+=w[i];sumv+=v[i];i++;
	} 
	if(i<=n) e.ub=sumv+(W-sumw)*v[i]/w[i];
	else e.ub=sumv;
}
void EnQueue(node e,priority_queue<node> &qu){
	if(e.height==n){ //已经是叶子节点了 
		if(e.value>maxv){
			maxv=e.value;
			for(int i=1;i<=n;i++) visited[i]=e.x[i];
		}
	}
	else qu.push(e);
}
void bfs(){
	node e,e1,e2; //根节点为e 孩子为e1和e2 后续主要就是为该节点进行重置 
	e.height=0;e.value=0;e.weight=0;e.id=counts++;
	for(int i=1;i<=n;i++) e.x[i]=0;
	bound(e);//求其上界
	priority_queue<node>qu;
	qu.push(e); //根节点入队列 
	while(!qu.empty()){
		e=qu.top();qu.pop();//普通队列qu.front()  优先级是qu.top() 
		if(e.weight+w[e.height+1]<=W){ //左剪枝：检查左孩子 (选中)
			e1.id=counts++;e1.height=e.height+1;
			e1.weight=e.weight+w[e1.height];
			e1.value=e.value+v[e1.height];
			for(int j=1;j<=n;j++) e1.x[j]=e.x[j];e1.x[e1.height]=1;
			bound(e1);
			EnQueue(e1,qu);
		}
		//接下来是右孩子
		e2.id=counts++;e2.height=e.height+1;
		e2.value=e.value;e2.weight=e.weight;
		for(int j=1;j<=n;j++) e2.x[j]=e.x[j];e2.x[e2.height]=0;
		bound(e2);
		if(e2.ub>maxv) EnQueue(e2,qu);//右剪枝：价值上界可以超过当前的最大价值 就可以不被剪枝 
	} 
}
int main(){
	bfs();//0.0328s 
	printf("%d",maxv);
	return 0; 
} 



