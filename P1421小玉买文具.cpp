#include<bits/stdc++.h>
using namespace std;
int main(){
	int x,y;
	cin>>x>>y;
	int totalprice = x*10+y;
	int spendprice = 19;
	cout<<floor(totalprice/spendprice);
}
