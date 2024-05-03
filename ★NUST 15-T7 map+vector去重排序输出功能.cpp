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
	//map不能排序 要转成vector再用sort对值进行排序
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++)
		vec.push_back(make_pair(it->first,it->second));
	//排序 sort默认为递增 递减;.要定义函数 且是vector排序的sort 
	sort(vec.begin(),vec.end(),cmp);
	for(vector<pair<int,int>>::iterator it=vec.begin();it!=vec.end();it++){
		if(it->first!=0){
			printf("%d:%d",it->first,it->second);
			if(it+1!=vec.end()) cout<<","; 
		}
	}
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
