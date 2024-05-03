#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int n;
//����1:����һ��ʼ�õ���bool ����ֵһ�����Ĳ���1 �ͻ�Ĭ��Ϊ1 �ͻᵼ�³��� 
//����2:MAXN����ֵһ��ʼ��С�� Ӧ�ô�����
//����3:��i��Ϊdfs�� ÿ������ѭ������������˼���һ�νӴ� 
int lie_flag[MAXN];
int hang_flag[MAXN];
int zhu_xie_flag[MAXN];//i-j+nΨһ��Ӧ 
int fu_xie_flag[MAXN];//i+jΨһ��Ӧ 
int counts=0;
void print(){
	counts++;
	if(counts<=3){
		for(int i=1;i<=n;i++) 
			printf("%d ",hang_flag[i]);
		printf("\n");
	}
}
void dfs(int i){ //��iΪ�� ����ѭ��j��ʾÿһ�� 
	if(i>n){
		print();
		return;
	}
	for(int j=1;j<=n;j++){  //j��ʾÿһ�� 
		if(lie_flag[j]==0 && hang_flag[i]==0 && zhu_xie_flag[i-j+n]==0 && fu_xie_flag[i+j]==0){
			lie_flag[j]=1;hang_flag[i]=j;zhu_xie_flag[i-j+n]=1;fu_xie_flag[i+j]=1;dfs(i+1);
			lie_flag[j]=0;hang_flag[i]=0;zhu_xie_flag[i-j+n]=0;fu_xie_flag[i+j]=0;//���� 
		}
	}
}

int main(){
	scanf("%d",&n);
	fill(lie_flag,lie_flag+MAXN,0);
	fill(hang_flag,hang_flag+MAXN,0);
	fill(zhu_xie_flag,zhu_xie_flag+MAXN,0);
	fill(fu_xie_flag,fu_xie_flag+MAXN,0);
	dfs(1);
	printf("%d",counts); 
	return 0;
}



