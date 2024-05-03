#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
string a,b;
int main(){
	getline(cin,a);getline(cin,b);int ans=0;
	for(int i=0;i<a.length();i++) a[i]=tolower(a[i]);
	for(int j=0;j<b.length();j++) b[j]=tolower(b[j]);
	a=' '+a+' ';b=' '+b+' ';
	if(b.find(a)==string::npos){printf("-1");return 0;}
	int tmp1=b.find(a);int tmp2=tmp1;
	while(tmp2!=string::npos){
		ans++;tmp2=b.find(a,tmp2+1);
	}
	printf("%d %d",ans,tmp1);
	return 0;
}

