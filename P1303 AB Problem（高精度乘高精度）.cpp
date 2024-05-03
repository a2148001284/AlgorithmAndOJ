#include<bits/stdc++.h>
using namespace std;
char s1[10001],s2[10001];
int a[10001],b[10001],c[10001];
int main(){
	cin>>s1>>s2;int la=strlen(s1);int lb=strlen(s2);
	for(int i=0;i<la;i++) a[la-i]=s1[i]-'0';
	for(int i=0;i<lb;i++) b[lb-i]=s2[i]-'0';
	int lc=la+lb;//乘法结果最大长度是两者长度之和  
	for(int i=1;i<=la;i++){
		for(int j=1;j<=lb;j++){
			c[i+j-1]+=a[i]*b[j];
			c[i+j]+=c[i+j-1]/10;
			c[i+j-1]%=10;
		}
	}
	while(c[lc]==0&&lc>1) lc--;
	for(int i=lc;i>0;i--) cout<<c[i];
	return 0;
}
