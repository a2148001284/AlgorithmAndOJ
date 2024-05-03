#include<bits/stdc++.h>
using namespace std;
//5432123456788881
int main(){
	string res;
	cin>>res;
	int len = res.length();int JiSum=0;int OuSum=0;
	for(int i=len-1;i>=0;i--){
		if((i+1)%2==0){
			int tmp=(res[i]-'0')*2;
			if(tmp/10!=0) tmp-=9;
			OuSum+=tmp;
		}
		if((i+1)%2==1) JiSum+=(res[i]-'0');
	}
	if((JiSum+OuSum)%10==0) cout<<"合法"<<endl;
	else cout<<"不合法"<<endl;
	return 0;
}
