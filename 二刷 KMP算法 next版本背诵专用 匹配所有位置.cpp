#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
//KMP�㷨���а� ƥ������λ�� 
int main(){
	string a,b;//aΪ���Դ� bΪĿ�괮
	getline(cin,a);getline(cin,b);int len=a.length();int next[len+1];
	//���������next����
	int i=0,j=-1;next[0]=-1;
	while(i<=int(b.length())){
		if(j==-1||b[i]==b[j]) ++i,++j,next[i]=j;
		else j=next[j];
	}
	//����������ƥ�� 
	i=0,j=0;
	while(i<=int(a.length())&&j<=int(b.length())){
		if(j==-1||a[i]==b[j]) ++i,++j;
		else j=next[j];
		if(j>=int(b.length())) j=next[j],printf("λ����%d\n",i-int(b.length())+1);
	}
	return 0;
}
