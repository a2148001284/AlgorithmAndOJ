#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
//sort �������ȶ���O(nlogn) 
//sort�Ӵ�С��������� 
//bool cmp(int o,int p){
//	return o>p;//biggest is first
//}
int main(){
	int n,a[100002];  //10��5�η���10,0000 Ҫ��ʮ��Ĵ�С 
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
	return 0;
}
