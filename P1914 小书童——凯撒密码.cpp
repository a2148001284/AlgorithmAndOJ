#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
	string res;cin>>res;
	//fun1
//	for(int i=0;i<res.length();i++){
//		if(int(res[i])+n > 122){
//			res[i]=char(96+int(res[i])+n-122); 
//		}else{
//			res[i]=char(int(res[i])+n); 
//		}
//	}
//	for(int i=0;i<res.length();i++) cout<<res[i];

	//fun2
	for(int i=0;i<res.length();i++){
		//cout<<(res[i]-'a'+n)%26+'a'; 
		putchar((res[i]-'a'+n)%26+'a');  //将int 输出为char形式 
	}
	return 0;
}
