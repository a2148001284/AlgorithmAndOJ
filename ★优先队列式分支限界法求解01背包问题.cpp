#include<bits/stdc++.h>
#define MAXN 1000
#define INT INT_MAX
using namespace std;
int n=3,W=30;
int w[]={0,16,15,15};
int v[]={0,45,25,25};
int maxv=-INT;bool visited[MAXN];int counts=0;//��ſ��Ʊ��� 
struct node{
	int id;
	int height;//�ڵ�Ĳ�� 
	int weight;//��ǰ�ڵ�������� 
	int value;//��ǰ�ڵ���ܼ�ֵ 
	int x[MAXN];//��ǰ�ڵ�����Ľ�����
	double ub;//��ֵ�Ͻ� 
	friend bool operator <(node a,node b){
		return a.ub<b.ub;//����ѡ���ֵ�Ͻ����� ���Ը��õļ�֦ 
	}
};
void bound(node &e){ //���������ֵ ����Ŀ�������Ͻ� �������ڼ�֦ 
	int i=e.id+1;int sumw=e.weight;//��װ��������� 
	double sumv=e.value;//��װ����ܼ�ֵ
	while((sumw+w[i]<=W)&&i<=n){
		sumw+=w[i];sumv+=v[i];i++;
	} 
	if(i<=n) e.ub=sumv+(W-sumw)*v[i]/w[i];
	else e.ub=sumv;
}
void EnQueue(node e,priority_queue<node> &qu){
	if(e.height==n){ //�Ѿ���Ҷ�ӽڵ��� 
		if(e.value>maxv){
			maxv=e.value;
			for(int i=1;i<=n;i++) visited[i]=e.x[i];
		}
	}
	else qu.push(e);
}
void bfs(){
	node e,e1,e2; //���ڵ�Ϊe ����Ϊe1��e2 ������Ҫ����Ϊ�ýڵ�������� 
	e.height=0;e.value=0;e.weight=0;e.id=counts++;
	for(int i=1;i<=n;i++) e.x[i]=0;
	bound(e);//�����Ͻ�
	priority_queue<node>qu;
	qu.push(e); //���ڵ������ 
	while(!qu.empty()){
		e=qu.top();qu.pop();//��ͨ����qu.front()  ���ȼ���qu.top() 
		if(e.weight+w[e.height+1]<=W){ //���֦��������� (ѡ��)
			e1.id=counts++;e1.height=e.height+1;
			e1.weight=e.weight+w[e1.height];
			e1.value=e.value+v[e1.height];
			for(int j=1;j<=n;j++) e1.x[j]=e.x[j];e1.x[e1.height]=1;
			bound(e1);
			EnQueue(e1,qu);
		}
		//���������Һ���
		e2.id=counts++;e2.height=e.height+1;
		e2.value=e.value;e2.weight=e.weight;
		for(int j=1;j<=n;j++) e2.x[j]=e.x[j];e2.x[e2.height]=0;
		bound(e2);
		if(e2.ub>maxv) EnQueue(e2,qu);//�Ҽ�֦����ֵ�Ͻ���Գ�����ǰ������ֵ �Ϳ��Բ�����֦ 
	} 
}
int main(){
	bfs();//0.0328s 
	printf("%d",maxv);
	return 0; 
} 



