#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>//fillʹ�õ�ͷ�ļ� 
using namespace std;
//����ÿһ����ȷ���� ��Χ�������ٱ�ѡ�� ��Ӱ����һ�� ���Բ����ö�̬�滮/̰��
//dfs���� �������� ��������������Ƿ񻹿��Ա�ȡ
int n,m;int number[10][10];int t;int chos[10][10];//����� ��ֵ��ʱ���������±�Խ�������Ҫ���� 
int maxstarg=0;int tmpmax=0;
int xx[9]={0,-1,-1,-1,0,0,1,1,1};//����2 id=0û���� ��������Խ�� 
int yy[9]={0,1,0,-1,1,-1,1,0,-1}; 
//ֵ��ѧϰ:����ѭ��ÿ�������� ����ѡ�Ͳ�ѡ Ȼ����� 
void dfs(int x,int y){
	//if(x<1 || y<1 || y>n) return;//����1:��һ��x==n+1 ����������ͻ�� ��Խ��û��Ҫ����,���������� ����Ҫ����  
	if(x==n+1){
		maxstarg=max(maxstarg,tmpmax);return;
	} //��ֹ���� 
	if(y==m) dfs(x+1,1); else dfs(x,y+1);//��ʾ��ǰ�㲻ѡ ֱ������һ�� 
	if(chos[x][y]==0){ //��ǰ�����ѡ ��ѡȡ 
		for(int i=1;i<=8;i++) chos[x+xx[i]][y+yy[i]]++;//�����Χ�ĵ� �����ٷ����� 
		tmpmax+=number[x][y];if(y==m) dfs(x+1,1); else dfs(x,y+1); 
		for(int i=1;i<=8;i++) chos[x+xx[i]][y+yy[i]]--;tmpmax-=number[x][y];//���� 
		//����3:chos������bool��ʾ ��ǰ�Ƿ���Է��� ��Ϊ�����ѵ�ʱ���漰���ܶ���ظ�����,ֻ�л��ݵ���ļ�Ϊ0������Ŀ��Է��� 
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
