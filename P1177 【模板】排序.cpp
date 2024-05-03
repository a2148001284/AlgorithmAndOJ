#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//sort 本身是稳定的O(nlogn) 
//sort从大到小排序的重载 
//bool cmp(int o,int p){
//	return o>p;//biggest is first
//}
int main(){
	int n,a[100002];  //10的5次方是10,0000 要开十万的大小 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
