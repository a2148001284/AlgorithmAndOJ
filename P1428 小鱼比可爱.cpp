#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	for(int t=0;t<n;t++){ //表示t轮 每轮输出一个数 
		int count=0;//统计数量 
		if(t>0){
			for(int i=0;i<t;i++){
				if(a[i]<a[t]) count++;
			}
		}
		cout<<count<<" ";
	}
	return 0;
}






