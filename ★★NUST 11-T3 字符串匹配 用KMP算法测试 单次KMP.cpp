#include<bits/stdc++.h>
using namespace std;
/*3����дһ��������void replace(char rs[],char a[],char s1[],const char s2[])��
���ַ���a�в����Ƿ���s1�Ӵ�������У��ͽ�s1�Ӵ��滻Ϊs2����
��󽫽����д�뵽�β�rs���У�дһ�����������Խ�����ļ���test3.cpp��*/
//strlen() �����ַ����ĳ��� ��/0��ֹ 

/** �����string��length���ص���unsigned int  ��-1��ת������� �ʱ���int()   */
const int MaxLen = 500;int len=0;
void get_nextval(string T,int nextval[]){
	int i=0,j=-1;
	nextval[0]=-1;
	while(i<int(T.length())){
		if(j==-1 || T[i]==T[j]){
			++i;++j;
			if(T[i]!=T[j]) nextval[i]=j;
			else nextval[i]=nextval[j];
		}else j=nextval[j];
	}
}

int Index_KMP(string S,string T,int next[]){
	int i=0,j=0;
	while(i<int(S.length()) && j<int(T.length())){
		if(j==-1 || S[i]==T[j]){
			++i;++j;
		}else{
			j=next[j];
		}
	}
	if(j>=int(T.length())){
		return i-int(T.length());  //�ִ���λ�� �±��0��ʼ�� 
	}else return 0;
} 

void replace(string rs,string a,string s1,string s2) {//a�в��ִ�s1  s2�������滻�� д��rs�� 
	int i=s1.length();int next[i];
	get_nextval(s1,next);
	for(int j=0;j<i;j++){
		cout<<next[j]<<" ";
	}
	int res=Index_KMP(a,s1,next);
	if(res==0){
		cout<<"ƥ��ʧ��"<<endl; return;
	}else{
		cout<<"success"<<endl; 
		cout<<res<<endl;
	}
}

int main(){
	string rs;string a;string s1;string s2;	
	cin>>a>>s1>>s2;
	replace(rs,a,s1,s2);
	//for(int i=0;i<len;i++) cout<<rs[i];
	return 0;
}
