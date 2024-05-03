#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[3];int mins;
	cin>>a[0]>>a[1]>>a[2];
	for(int i =0;i<3;i++){
		mins = i;
		for(int j =i+1;j<3;j++) if(a[j]<a[i]) mins = j;
		if(mins != i) swap(a[i],a[mins]);
	}
	cout<<a[0]<<" "<<a[1]<<" "<<a[2];
	return 0;
}
