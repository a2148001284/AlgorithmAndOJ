#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	int local = 5*n;
	int luogu = 3*n+11;
	if(local < luogu) cout<<"Local";
	else cout<<"Luogu";
	return 0;
}
