#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
bool visited[MAXV];//表明第i个物品有没有被选择
int maxv=0;//最优解的总价值 
int maxw=0;

//dfs3的右剪枝 bound=tv+r tv为当前已有的重量 r为剩余物品的总价值 
//bound表示沿着该方向选择得到物品的价值上界 只有bound>maxv 才有必要继续剪枝 否则没必要继续了
//故只有bound尽可能小 才能尽可能多的剪枝  即r尽可能小 所以需要所有物品按照单位重量价值递减排序 

//不适合用堆结构 因为后续会多次访问 堆出去以后就不能再用了 
//struct priority{
//	int id;
//	int weights;
//	int values;
//	double v_w;
//	friend bool operator <(priority a,priority b){
//		return a.v_w<b.v_w; //切记 friend 且priority_queue本身就是从大到小 所以都是<就是从大到小 
//	}
//};
//priority_queue<priority> q;
//void init(){
//	fill(visited,visited+MAXV,0);
//	cin>>n;cin>>Bag_Weight;
//	for(int i=1;i<=n;i++) cin>>weight[i];
//	for(int i=1;i<=n;i++) cin>>value[i];
//	for(int i=1;i<=n;i++){
//		q.push(priority{i,weight[i],value[i],double(value[i])/weight[i]});
//	} 
//}

struct node{
	int weights;
	int values;
	double v_w;
}A[MAXV];

bool cmp(node a,node b){
	return a.v_w>b.v_w;
}

void init(){
/**
4 6
5 4
3 4
2 3
1 1
 **/
	fill(visited,visited+MAXV,0);
	cin>>n;cin>>Bag_Weight;
	for(int i=1;i<=n;i++){
		cin>>A[i].weights;cin>>A[i].values;
		A[i].v_w=double(A[i].values)/A[i].weights;
	}
	sort(A+1,A+n+1,cmp);
}

//3.重量不超过W的算法 含左剪枝和右剪枝
int bound(int i,int tw,int tv){
	i++;
	while(i<=n && tw+A[i].weights<=Bag_Weight){
		tw+=A[i].weights;
		tv+=A[i].values;
		i++;
	}
	if(i<=n){
		return tv+(Bag_Weight-A[i].weights)*A[i].v_w;
	}else return tv;
} 

void dfs(int i,int tw,int tv,int op[]){ //rw为当前行及以后所有物品的重量 右剪枝判断需要 
	if(i>n){
		maxv = max(maxv,tv);
		for(int i=1;i<=n;i++) visited[i]=op[i];
	} else{
		if(tw+A[i].weights<=Bag_Weight) { //左剪枝 如果选中后重量已经超过可容纳的值 就不用继续讨论了 
			op[i]=1;dfs(i+1,tw+A[i].weights,tv+A[i].values,op);
		}
		if(bound(i,tw,tv)>maxv){
			op[i]=0;dfs(i+1,tw,tv,op);
		}
	}
}

void DisChoose(){
	for(int i=1;i<=n;i++)
		if(visited[i]) cout<<"物品"<<i<<" 重量为:"<<A[i].weights<<" 价值为:"<<A[i].values<<"  被选择了"<<endl; 
}

int main(){
	//2.重量不超过W的算法 此时左剪枝不变 但右剪枝需要改动 
	init();int tmp[MAXV];
	dfs(1,0,0,tmp);
	cout<<maxv<<endl;
	DisChoose();
	return 0;
}




