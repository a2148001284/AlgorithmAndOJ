#include<bits/stdc++.h>
using namespace std;
char a[1002][1002];
int visited[1002][1002];int n,m;
//�����ü��仯�Ż� ��Ϊ��������ݿ����ظ� ���Բ��ü���ķ��� 
//ans��¼ÿһ������Ķ�Ӧ�����Ž�
//visited�����Ƿ񱻷��� ���仯�Ż� ʹ���¼����flag������0��1 ��������ֱ���ҵ����Ӧ���ִ� �����μ��� 
int ans[100002];
void dfs(int x,int y,int flag,int tag){
	if(visited[x][y]!=-1 || x<0 || x>=n || y<0 || y>=n || tag!=a[x][y]-'0') return;
	visited[x][y]=flag;ans[flag]++;
	dfs(x+1,y,flag,!tag);
	dfs(x-1,y,flag,!tag);
	dfs(x,y+1,flag,!tag);
	dfs(x,y-1,flag,!tag);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++) scanf("%s",a[i]);
	fill(visited[0],visited[0]+1002*1002,-1);
	for(int j=0;j<m;j++){
		int tmp1,tmp2;scanf("%d%d",&tmp1,&tmp2);tmp1--;tmp2--;
		if(visited[tmp1][tmp2]==-1) dfs(tmp1,tmp2,j,a[tmp1][tmp2]-'0');
		else ans[j]=ans[visited[tmp1][tmp2]];  //���仯���� ���ı���TLE 
	}
	for(int i=0;i<m;i++) cout<<ans[i]<<endl;
	return 0;
}





