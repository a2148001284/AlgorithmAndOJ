#include<bits/stdc++.h>
using namespace std;
//��KMP�������ַ���ƥ������� 
//���ڵ����⣺�ٵ��ʿ��ܴ��ڴ�Сд����  �ڿ����Ե���Ϊ��λ �������ַ�Ϊ��λ����ƥ�� 
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
	int i=0,j=0;int ans=0;//ans�洢ƥ��ɹ��Ĵ��� 
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
	//scanf("%s",&targ);scanf("%s",&init);  ���ո���ַ��� cin��scanf��ͣ 
	int i=int(targ.length());int nextval[i];
	get_nextVal(targ,nextval);
	KMP(init,targ,nextval);
	return 0;
}







