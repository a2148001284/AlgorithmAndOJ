#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	string ticket;
	int len;
//	friend bool operator < (node a,node b){
//		return a.ticket>b.ticket;
//	}
}Candidate[23];
bool cmp(node a,node b){//Ĭ�ϰ��մӴ�С���� 
	if(a.len!=b.len) return a.len>b.len; //��һ��׼���ճ��� ���Ȳ���ʱ �������� 
	else return a.ticket>b.ticket; //�������ʱ �����ֵ����string�������� 
}
int main(){
	//˵��string�Ƚϰ����ֵ������αȽ�  
//	string a="44563";
//	string b="12324343";
//	cout<<(a>b)<<endl;//true 
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		Candidate[i].id=i;string tmp;cin>>tmp;
		Candidate[i].ticket=tmp;Candidate[i].len=tmp.length();
	}
	sort(Candidate+1,Candidate+n+1,cmp);
	cout<<Candidate[1].id<<endl<<Candidate[1].ticket;
	return 0;
}





