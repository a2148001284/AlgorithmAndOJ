#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;double sum=0;
	for(int i=1;i<=n;i++){
		double temp = 1.0/i;
		sum+=temp;
	}
	//printf("%.6f",sum);
	cout<<fixed<<setprecision(6)<<sum;
	return 0;
}
