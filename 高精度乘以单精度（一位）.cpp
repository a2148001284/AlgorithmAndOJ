#include<bits/stdc++.h>
using namespace std;
int main(){
	char A[250];//存最初输入的内容
	int a[250]; long long beichengshu;
	cin>>A>>beichengshu;int len=strlen(A);
	for(int i=0;i<len;i++) a[len-i]=A[i]-'0';
	int len2 = len+1;
	for(int i=1;i<=len2;i++){
		a[i]+=a[i]*beichengshu;
		a[i+1]=a[i]/10;
		a[i]=a[i]%10;
	}
	if(a[len2]==0 && len2>0) len2--;
	for(int i=len2;i>0;i--) cout<<a[i];
	return 0; 
}
