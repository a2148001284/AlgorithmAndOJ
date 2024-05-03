#include<bits/stdc++.h>
using namespace std;
long long DieDai(int n,int m){
	long long res=1;
	m = min(m,n-m);
	for(int i=0;i<m;i++){
		res *= (n-i);
		res /= (i+1);
	} 
	return res;
}

long long DiGui(int n,int m){
	if(m==0 || m==n) return 1;
	return DiGui(n-1,m-1)+DiGui(n-1,m);
}

int main(){ 
	//会爆 别用这个方法 (求组合数不能直接乘 n超过10就容易爆了)
//	int n;cin>>n;
//	long long sum1=1;long long sum2=1;
//	for(int i=0;i<n;i++){
//		sum1*=(2*n-i);
//		sum2*=(n-i);
//	}
//	cout<<sum1/(sum2*(n+1));
	int n;cin>>n;
	long long x = DieDai(2*n,n);
	//int x = DiGui(2*n,n);
	cout<<x/(n+1);
	return 0;
}
