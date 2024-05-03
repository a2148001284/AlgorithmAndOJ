#include<bits/stdc++.h>
using namespace std;
/*3、编写一个函数：void replace(char rs[],char a[],char s1[],const char s2[])，
在字符串a中查找是否有s1子串，如果有，就将s1子串替换为s2串，
最后将结果串写入到形参rs串中，写一个主函数测试结果（文件名test3.cpp）*/
//strlen() 计算字符串的长度 到/0截止 

/** ★★★★string的length返回的是unsigned int  则-1的转换会出错 故必须int()   */
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
		return i-int(T.length());  //字串的位置 下标从0开始的 
	}else return 0;
} 

void replace(string rs,string a,string s1,string s2) {//a中查字串s1  s2是用于替换的 写到rs中 
	int i=s1.length();int next[i];
	get_nextval(s1,next);
	for(int j=0;j<i;j++){
		cout<<next[j]<<" ";
	}
	int res=Index_KMP(a,s1,next);
	if(res==0){
		cout<<"匹配失败"<<endl; return;
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
