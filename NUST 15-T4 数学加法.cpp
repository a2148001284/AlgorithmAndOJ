#include<bits/stdc++.h>
using namespace std;
int GetNum(int a,int v){
	int x=0;
	for(int i=1;i<=v;i++){
		x+=a*pow(10,i-1);
	}
	return x;
}
int main(){
	int n,a;cin>>a>>n;long long sum=0;int s=0;
//	for(int i=1;i<=n;i++){
//		sum+=GetNum(a,i);
//	}
	//ÓÅ»¯
	for(int i=1;i<=n;i++){
		s=s*10+a;
		sum+=s;
	} 
	cout<<sum;
	return 0;
}
