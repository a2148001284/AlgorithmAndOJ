#include<bits/stdc++.h>
using namespace std;
int a[1002][1002];
int visited[1002][1002];int n,m;
//�����ü��仯�Ż� ��Ϊ��������ݿ����ظ� ���Բ��ü���ķ��� 
//ans��¼ÿһ������Ķ�Ӧ�����Ž�
//visited�����Ƿ񱻷��� ���仯�Ż� ʹ���¼����flag������0��1 ��������ֱ���ҵ����Ӧ���ִ� �����μ��� 
int ans[100002];
void dfs(int x,int y,int flag){
	if(visited[x][y]!=-1 || x<1 || x>n || y<1 || y>n) return;
	visited[x][y]=flag;ans[flag]++;
	if(a[x+1][y]!=a[x][y]) dfs(x+1,y,flag);
	if(a[x-1][y]!=a[x][y]) dfs(x-1,y,flag);
	if(a[x][y+1]!=a[x][y]) dfs(x,y+1,flag);
	if(a[x][y-1]!=a[x][y]) dfs(x,y-1,flag);
}
int main(){
	scanf("%d%d",&n,&m);
	//һֱ���ִ��ԭ������: ���� 010101/10=416 0��ͷ�����ֱ������˰˽��� 
//	for(int i=1;i<=n;i++){
//		int targ;scanf("%d",&targ);
//		for(int j=n;j>=1;j--){
//			a[i][j]=targ%10;
//			targ/=10;
//		}
//	}
	//��ȷ���뷽�� ���ַ�����+��� 
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			char ch;cin>>ch;a[i][j]=ch-'0';
		} 
	fill(ans,ans+100002,0);
	fill(visited[0],visited[0]+1002*1002,-1);//��ά����ĸ�ֵ��ʽ��[0] 
	for(int j=1;j<=m;j++){
		int tmp1,tmp2;scanf("%d %d",&tmp1,&tmp2);
		if(visited[tmp1][tmp2]==-1) dfs(tmp1,tmp2,j);
		else ans[j]=ans[visited[tmp1][tmp2]];  //���仯���� ���ı���TLE 
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}



