#include<bits/stdc++.h>
using namespace std;
void get_nextval(string targs,int nextval[]){
	int i=0,j=-1;nextval[0]=-1;
	while(i<=int(targs.length())){
		if(j==-1 || targs[i]==targs[j]){
			++i,++j;
			if(targs[i]!=targs[j]) nextval[i]=j;
			else nextval[i]=nextval[j];
		}else j=nextval[j];
	}
}
void get_next(string targs,int next[]){
	int i=0,j=-1;next[0]=-1;
	while(i<=int(targs.length())){
		if(j==-1 || targs[i]==targs[j]){
			++i,++j;next[i]=j;
		}else j=next[j];
	}
}
void KMP(string init,string targs,int nextval[]){
	int i=0,j=0;
	while(i<int(init.length())&&j<int(targs.length())){
		if(init[i]==targs[j] || j==-1) ++i,++j;
		else j=nextval[j];
		if(j>=int(targs.length())) j=nextval[j],printf("%d\n",i-int(targs.length())+1);
	}
}
void print(int nextval[],int len){
	//cout<<0<<" "; 
	for(int i=0;i<len;i++) cout<<nextval[i]<<" ";
}
int main(){
	string a,b;cin>>a>>b;
	int i=b.length();int next[i];
	//get_nextval(b,nextval);
	get_next(b,next);
	KMP(a,b,next);
	print(next,i); 
	return 0;
}

