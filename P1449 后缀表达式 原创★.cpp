#include<bits/stdc++.h>
#define INF INT_MAX
using namespace std;
//后缀表达式
stack<int> q;
void opera(char ope){
	int oper1,oper2;oper2=q.top();q.pop();
	oper1=q.top();q.pop();
	if(ope=='+') q.push(oper1+oper2);
	else if(ope=='-') q.push(oper1-oper2);
	else if(ope=='*') q.push(oper1*oper2);
	else if(ope=='/') q.push(oper1/oper2);
	//cout<<"--->"<<q.top()<<endl;
}

int main(){
	//c++的 stoi() 可以把string转成int 
	//string a="12";int tar = stoi(a);cout<<tar<<endl;
	int targ=INF;
	while(1){
		char tmp;scanf("%c",&tmp);
		if(tmp=='@'){ printf("%d",q.top());break; }
		else if(tmp>='0' && tmp<='9'){
			if(targ==INF) targ=0;
			targ=targ*10+(tmp-'0');
		}
		else if(tmp=='.'){
			if(targ!=INF) q.push(targ),targ=INF;
			continue;
		}
		else opera(tmp);
	}
	return 0;
}








 
