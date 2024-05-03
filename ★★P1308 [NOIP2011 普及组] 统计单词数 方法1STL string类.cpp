#include<bits/stdc++.h>
using namespace std;
//使用STL的string类进行操作 
int main(){
	string init;string targ;
	getline(cin,targ);getline(cin,init);
	//isupper是判断是否是大写字母的系统函数，tolower是将其转换成小写字母的函数 toupper是转大写 
	for(int i=0;i<init.length();i++) init[i]=tolower(init[i]);
	for(int j=0;j<targ.length();j++) targ[j]=tolower(targ[j]);
	//★由于是要求给定单词完全匹配  不能匹配部分 所以要首尾加空格 空格数量要相同
	init=' '+init+' ';
	targ=' '+targ+' '; 
	if(init.find(targ)==string::npos){
		printf("-1");
	}else{
		int ans=0;
		//不要连着写 会出错 两个变量就重新写两个 
		//int first_pos,first_pos2=init.find(targ);cout<<first_pos<<" "<<first_pos2<<endl; //8 0
		int first_pos=init.find(targ);int first_pos2=init.find(targ);//cout<<first_pos<<" "<<first_pos2<<endl; 0 0
		while(first_pos2 != string::npos){
			ans++;first_pos2=init.find(targ,first_pos2+1);//find找到的是第一次出现的位置 +1才能继续 
		}
		printf("%d %d",ans,first_pos);
	}
	return 0;
} 








