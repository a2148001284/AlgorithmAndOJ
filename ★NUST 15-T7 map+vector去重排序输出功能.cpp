#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;
} 

int main(){
	map<int,int> mp;
	vector<pair<int,int>> vec; 
	while(1){
		int x;cin>>x;if(x==-1) break;
		mp[x]++;
	}
	//map�������� Ҫת��vector����sort��ֵ��������
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		vec.push_back(make_pair(it->first,it->second));
	//���� sortĬ��Ϊ���� �ݼ�;.Ҫ���庯�� ����vector�����sort 
	sort(vec.begin(),vec.end(),cmp);
	for(vector<pair<int,int>>::iterator it=vec.begin();it!=vec.end();it++){
		if(it->first!=0){
			printf("%d:%d",it->first,it->second);
			if(it+1!=vec.end()) cout<<","; 
		}
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
