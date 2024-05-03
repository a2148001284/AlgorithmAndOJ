#include<bits/stdc++.h>
using namespace std;int N;
bool IsZhishu(int x){
	int i;
	for(i=2;i<=sqrt(x);i++) if(x%i==0) return false;
	if(i>sqrt(x)) return true;
}
void dfss(int x){
	for(int j=2;j<=x-2;j++){
		if(IsZhishu(j) && IsZhishu(x-j)){
			cout<<x<<"="<<j<<"+"<<x-j<<endl;return;
		}
	}
}
int main(){
	scanf("%d",&N);
	for(int i=4;i<=N;i+=2) dfss(i);
	return 0;
}




