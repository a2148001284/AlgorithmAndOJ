#include<bits/stdc++.h>
#define MAXN 105
using namespace std;
//01�������� dp��̬�滮
//dp[i][j] ����ǰi����Ʒ�������,��������Ϊjʱ �õ�������ֵ
int T,M;int value[MAXN];int weight[MAXN];//TΪ�������� MΪ��Ʒ���� 
bool visited[MAXN];int dp[MAXN][1005];int maxv=0;//��������ȵ�ԭ��dp����Ĵ�С����� dp[i][j] ����i����Ʒ����������ʣ��jʱ�� ����ֵ 
int dp2[1005];
void init(){
	scanf("%d%d",&T,&M); 
	for(int i=1;i<=M;i++) scanf("%d%d",&weight[i],&value[i]);
}
void GetDp(){ //��ά���鷽ʽ 
	for(int i=0;i<=M;i++) dp[i][0]=0;
	for(int j=0;j<=T;j++) dp[0][j]=0;
	for(int i=1;i<=M;i++)
		for(int j=1;j<=T;j++){ 
			if(weight[i]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],dp[i-1][j-weight[i]]+value[i]);
		}
}
void GetDp2(){ //�Ż�dp ��һλ����+ѭ������ ���ٿռ��ʹ�� 
	//�߽����� �������iΪ�κ�ֵ ��������Ϊ0��ʱ�� ��ֵ����0
	dp2[0]=0; 
	 for(int i=1;i<=M;i++)
	 //��j�ķ�Χ������j>=1 ��Ϊj-weight[i]���ɸ��� 
	 	for(int j=T;j>=weight[i];j--){ //���ڲ��Ƕ�ά���� dp2[j-weight[i]] ���ȱ����� �Ӷ����´��� ����Ҫ������� 
		 	if(j<weight[i]) dp2[j]=dp2[j];//��仰���� ���Բο����µĶ�ˢ���Ǹ�cpp���� 
		 	else dp2[j]=max(dp2[j],dp2[j-weight[i]]+value[i]);
		 }
	//���ս���洢��dp2[T] Ĭ���Ǹ�����i=M�� ������M����Ʒ�� ��������ΪT������������ֵ 
	//���Ƕ�ʧ��ѡ������ Ҫ�������ʹ�ö�ά����鿴 
	
}
void GetChoose(){
	int n=M;int r=T;//nΪ���� rΪʱ��/���� 
	while(n>=0){
		if(dp[n][r]!=dp[n-1][r]){
			visited[n]=1;r=r-weight[n];maxv+=value[n];
		} 
		n--;
	}
}
int main(){
	init();
	//GetDp();
	//GetChoose();
	//printf("%d",dp[M][T]);
	GetDp2();
	printf("%d",dp2[T]);
	//printf("%d",maxv);
	return 0;
}

 




