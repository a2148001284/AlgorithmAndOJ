#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	map<int,int> mp;//int的初值没设置则默认为0 
	for(int i=0;i<n;i++){
		int temp;cin>>temp;
		mp[temp]++; 
	}
	//迭代器访问map 
	for(map<int,int>::iterator it=mp.begin();it!=mp.end();it++){
		if(it->second %2 !=0){
			cout<<it->first;break;
		}
	}
	return 0;
} 
