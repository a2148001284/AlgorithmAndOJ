#include<bits/stdc++.h>
using namespace std;
//��ѵ�������
int n,k;//nΪ�������� kΪ����������
int x[100];//����
int x1[100];//��ҵ
int mintime=INT_MAX;
/**
7 3
2 14 4 16 6 5 3
 **/
void dfs(int h){//h��Եĵڼ������� 
	if(h>n){
		int tmp=0;
		for(int i=1;i<=k;i++){
			if(x[i]>tmp) tmp=x[i];//�ҵ����л�������ʱ���Ļ��� 
		}
		mintime=min(mintime,tmp);
	}else{
		for(int i=1;i<=k;i++){
			x[i]+=x1[h];
			dfs(h+1);
			x[i]-=x1[h];
		}
	}
}
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>x1[i];dfs(1);
	cout<<mintime;return 0;
} 
