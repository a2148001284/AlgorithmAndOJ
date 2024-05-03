#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
bool visited[MAXV];//������i����Ʒ��û�б�ѡ��
int maxv=0;//���Ž���ܼ�ֵ 
int maxw=0;

//dfs3���Ҽ�֦ bound=tv+r tvΪ��ǰ���е����� rΪʣ����Ʒ���ܼ�ֵ 
//bound��ʾ���Ÿ÷���ѡ��õ���Ʒ�ļ�ֵ�Ͻ� ֻ��bound>maxv ���б�Ҫ������֦ ����û��Ҫ������
//��ֻ��bound������С ���ܾ����ܶ�ļ�֦  ��r������С ������Ҫ������Ʒ���յ�λ������ֵ�ݼ����� 

//���ʺ��öѽṹ ��Ϊ�������η��� �ѳ�ȥ�Ժ�Ͳ��������� 
//struct priority{
//	int id;
//	int weights;
//	int values;
//	double v_w;
//	friend bool operator <(priority a,priority b){
//		return a.v_w<b.v_w; //�м� friend ��priority_queue������ǴӴ�С ���Զ���<���ǴӴ�С 
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

//3.����������W���㷨 �����֦���Ҽ�֦
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

void dfs(int i,int tw,int tv,int op[]){ //rwΪ��ǰ�м��Ժ�������Ʒ������ �Ҽ�֦�ж���Ҫ 
	if(i>n){
		maxv = max(maxv,tv);
		for(int i=1;i<=n;i++) visited[i]=op[i];
	} else{
		if(tw+A[i].weights<=Bag_Weight) { //���֦ ���ѡ�к������Ѿ����������ɵ�ֵ �Ͳ��ü��������� 
			op[i]=1;dfs(i+1,tw+A[i].weights,tv+A[i].values,op);
		}
		if(bound(i,tw,tv)>maxv){
			op[i]=0;dfs(i+1,tw,tv,op);
		}
	}
}

void DisChoose(){
	for(int i=1;i<=n;i++)
		if(visited[i]) cout<<"��Ʒ"<<i<<" ����Ϊ:"<<A[i].weights<<" ��ֵΪ:"<<A[i].values<<"  ��ѡ����"<<endl; 
}

int main(){
	//2.����������W���㷨 ��ʱ���֦���� ���Ҽ�֦��Ҫ�Ķ� 
	init();int tmp[MAXV];
	dfs(1,0,0,tmp);
	cout<<maxv<<endl;
	DisChoose();
	return 0;
}




