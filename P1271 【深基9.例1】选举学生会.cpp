#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	int ticket[2000000];
	for(int i=0;i<m;i++) cin>>ticket[i];
	sort(ticket,ticket+m);
	for(int i=0;i<m;i++) cout<<ticket[i]<<" ";
	return 0;
}
