#include<bits/stdc++.h>
using namespace std;
int main(){
	int N;cin>>N;int a[102];int b[102];
	for(int i=0;i<N;i++) cin>>a[i];
	sort(a,a+N);int j=0;
	for(int i=0;i<N;i++){
		if(i>=1){
			if(a[i]==a[i-1]) continue;
		}
		b[j]=a[i];j++;
	}
	cout<<j<<endl;
	for(int i=0;i<j;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
