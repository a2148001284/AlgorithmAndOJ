#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int t=0;t<n;t++){ //��ʾt�� ÿ�����һ���� 
		int count=0;//ͳ������ 
		if(t>0){
			for(int i=0;i<t;i++){
				if(a[i]<a[t]) count++;
			}
		}
		cout<<count<<" ";
	}
	return 0;
}






