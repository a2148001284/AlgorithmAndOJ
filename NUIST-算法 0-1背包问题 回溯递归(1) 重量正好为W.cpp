#include<bits/stdc++.h>
#define MAXV 5000
using namespace std;
int n,weight[MAXV],value[MAXV];int Bag_Weight;
bool visited[MAXV];//������i����Ʒ��û�б�ѡ��
int maxv=0;//���Ž���ܼ�ֵ 
int maxw=0;int totalweight=0;//�Ҽ�֦Ҫ�� 
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

//1.�����Ż���dfs���ݵݹ���㷨 (�����պ�ΪW���㷨)
void dfs(int i,int tw,int tv,int op[]){ //twΪ����������� tvΪ������ܼ�ֵ iΪ��i�� 
	if(i>n){
		if(tw==Bag_Weight && tv>maxv){
			maxv=tv;maxw=tw;for(int j=1;j<=n;j++) visited[j]=op[j];
		}
	} else{
		op[i]=1;dfs(i+1,tw+weight[i],tv+value[i],op);
		op[i]=0;dfs(i+1,tw,tv,op);
	}
} 
//2.�����Ż� ���֦���Ҽ�֦  (�����պ�ΪW���㷨)
void dfs2(int i,int tw,int tv,int op[],int rw){ //rwΪ��ǰ�м��Ժ�������Ʒ������ �Ҽ�֦�ж���Ҫ 
	if(i>n){
		if(tw==Bag_Weight &&tv>maxv){
			maxv=tv;maxw=tw;for(int i=1;i<=n;i++) visited[i]=op[i];
		}
	} else{
		if(tw+weight[i]<=Bag_Weight) { //���֦ ���ѡ�к������Ѿ����������ɵ�ֵ �Ͳ��ü��������� 
			op[i]=1;dfs2(i+1,tw+weight[i],tv+value[i],op,rw-weight[i]);
		}
		if(tw+rw-weight[i]>=Bag_Weight){//�Ҽ�֦ ��ѡ��ǰ��Ʒ�� ����Ѻ���������Ʒ��ѡ�� �ǿ��Գ������������ ����Ͳ����ϸպ�ΪW ���Լ�֦ 
			op[i]=0;dfs2(i+1,tw,tv,op,rw-weight[i]); 
		}
	}
}

int main(){
	//1.�����պ�ΪW���㷨
	init();int tmp[MAXV];fill(tmp,tmp+MAXV,0);
	dfs(1,0,0,tmp); //0.8391s
	dfs2(1,0,0,tmp,totalweight);  //0.661s  ��֦�Ż���Ч 	
	cout<<maxv<<endl;
	return 0;
}






