#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int test[n];int mins;
	for(int i=0;i<n;i++){
		cin>>test[i];
		if(i==0) mins = test[0];
		if(test[i]<mins) mins=test[i];
	}
	cout<<mins;
	return 0;
}
