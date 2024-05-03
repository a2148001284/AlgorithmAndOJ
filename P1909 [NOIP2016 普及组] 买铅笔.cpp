#include<bits/stdc++.h>
using namespace std;
int main(){
	double n,number[3],price[3];
	cin>>n;
	for(int i=0;i<3;i++) cin>>number[i]>>price[i];
	int price1 = price[0]*(ceil(n/number[0]));
	int price2 = price[1]*(ceil(n/number[1]));
	int price3 = price[2]*(ceil(n/number[2]));
	int res = min(min(price1,price2),price3);
	cout<<res;
	return 0;
}
