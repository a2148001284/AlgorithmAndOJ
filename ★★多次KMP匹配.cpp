#include<bits/stdc++.h>
using namespace std;
//用KMP解决多次字符串匹配的问题 
//存在的问题：①单词可能存在大小写问题  ②可能以单词为单位 而不是字符为单位进行匹配 
void get_nextVal(string targs,int nextval[]){
	int i=0,j=-1;nextval[0]=-1;
	while(i<=int(targs.length())){
		if(j==-1 || targs[i]==targs[j]){
			++i;++j;
			if(targs[i]!=targs[j]) nextval[i]=j;
			else nextval[i]=nextval[j];
		}else j=nextval[j];
	}	
}
void KMP(string inits,string targs,int nextval[]){
	int i=0,j=0;int ans=0;//ans存储匹配成功的次数 
	int first_position=0;
	while(i<int(inits.length()) && j<int(targs.length())){
		if(inits[i]==targs[j] || j==-1){
			++i;++j;
		}else j=nextval[j];
		if(j>=int(targs.length())){
			ans++;j=nextval[j];
			if(ans==1) first_position=i-int(targs.length());
		} 
	} 
	if(ans>0){
		printf("%d %d",ans,first_position);
	}else printf("-1");
}
int main(){
	string init;string targ;
	getline(cin,targ);getline(cin,init);
	//scanf("%s",&targ);scanf("%s",&init);  含空格的字符串 cin和scanf会停 
	int i=int(targ.length());int nextval[i];
	get_nextVal(targ,nextval);
	KMP(init,targ,nextval);
	return 0;
}







