#include<bits/stdc++.h>
using namespace std;
void judgePrime(int x){
	if(x==1 || x<=0){
		cout<<"No Answer"<<endl<<0;
		return;
	}
	for(int i=2;i<=sqrt(x);i++){
		if(x%i==0){
			cout<<"No Answer"<<endl<<0;
			return;
		}
	}
	cout<<"Lucky Word"<<endl<<x;
	return;
} 
int main(){
	char danci[100];int counts[26]={0};
	cin>>danci;int len = strlen(danci);
	for(int i=0;i<len;i++){
		counts[danci[i]-'a']++;
	}
	int mins=101;//int mins=0;
	int maxs=0;
	for(int i=0;i<26;i++){
//		if(mins==0){
//			if(counts[i]>0) mins=counts[i];
//		}
		if(counts[i]>maxs) maxs=counts[i];
		if(counts[i]>0 && counts[i]<mins) mins=counts[i];
	}
	//cout<<"maxs:"<<maxs<<" mins:"<<mins;
	//判断质数:大于1(必须限制负数和0) 除了1和它本身 没有别的因数 1既不是质数也不是合数  
	judgePrime(maxs-mins);
	return 0;
}
