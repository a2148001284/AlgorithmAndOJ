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
bool cmp(node a,node b){//默认按照从大到小排序 
	if(a.len!=b.len) return a.len>b.len; //第一标准按照长度 长度不等时 长的优先 
	else return a.ticket>b.ticket; //长度相等时 按照字典序对string进行排序 
}
int main(){
	//说明string比较按照字典序依次比较  
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





