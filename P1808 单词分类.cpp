#include<bits/stdc++.h>
using namespace std;
int n;map<string,bool>targ;int sum;
//��õ��ͺܼ� �벻���ͺܸ��� 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string tmp;cin>>tmp;//getline(cin,tmp); getline��Ĭ�϶�ȡ�ո� ֻ�лس�Ϊ������ ��������̫�� ����û�л��� 
		sort(tmp.begin(),tmp.end());
		if(targ[tmp]==false) sum++,targ[tmp]=true;
	}
	printf("%d",sum);
	return 0;
}









