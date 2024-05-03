#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
//KMP算法背诵版 匹配所有位置 
int main(){
	string a,b;//a为初试串 b为目标串
	getline(cin,a);getline(cin,b);int len=a.length();int next[len+1];
	//接下来获得next数组
	int i=0,j=-1;next[0]=-1;
	while(i<=int(b.length())){
		if(j==-1||b[i]==b[j]) ++i,++j,next[i]=j;
		else j=next[j];
	}
	//接下来进行匹配 
	i=0,j=0;
	while(i<=int(a.length())&&j<=int(b.length())){
		if(j==-1||a[i]==b[j]) ++i,++j;
		else j=next[j];
		if(j>=int(b.length())) j=next[j],printf("位置是%d\n",i-int(b.length())+1);
	}
	return 0;
}
