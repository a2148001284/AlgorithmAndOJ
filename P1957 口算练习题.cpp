#include<bits/stdc++.h>
using namespace std;
int main(){
	int i;cin>>i;
	char sign;int oper1,oper2;char lastsign;
	for(int q=0;q<i;q++){
		if(q==0){
			cin>>sign>>oper1>>oper2;
			lastsign=sign;
		}else{
			string test;cin>>test;
			if(test !="a" && test!="b" && test!="c"){
				sign = lastsign;
				oper1 = stoi(test);//string可以用stoi 将string转int 
				cin>>oper2;
			}else{
				sign = test[0];
				lastsign = sign;//每轮都要记得更新lastsign 容易忘 
				cin>>oper1>>oper2;
			}
		}
		if(sign=='a'){
			string tar = to_string(oper1)+"+"+to_string(oper2)+"="+to_string(oper1+oper2);
			cout<<tar<<endl<<tar.length()<<endl;
		}else if(sign=='b'){
			string tar = to_string(oper1)+"-"+to_string(oper2)+"="+to_string(oper1-oper2);
			cout<<tar<<endl<<tar.length()<<endl;
		}else if(sign=='c'){
			string tar = to_string(oper1)+"*"+to_string(oper2)+"="+to_string(oper1*oper2);
			cout<<tar<<endl<<tar.length()<<endl;
		}
	}
	return 0;
}
