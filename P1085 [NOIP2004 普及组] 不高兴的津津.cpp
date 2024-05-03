#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[7];
	for(int i =0;i<=6;i++){
		int x,y;cin>>x>>y;
		a[i]=x+y;
	}
	int maxs = 0;int flag=0;
	for(int i=0;i<=6;i++){
		if(a[i]>8){
			if(flag == 0) maxs = i;
			flag=1;
			if(a[maxs]<a[i]) maxs=i;
		}
	}
	if(flag == 0) cout<<0;
	else cout<<maxs+1;
	return 0;
}
