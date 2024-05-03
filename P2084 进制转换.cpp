#include<bits/stdc++.h>
using namespace std;
int main(){
	int m;string targ;int mark=0;
	cin>>m>>targ;int flag=targ.length()-1;int i=0;
	while(i<=targ.length()-1){
		if(targ[i]!='0'){
			if(mark==1) cout<<"+"; 
			cout<<targ[i]<<"*"<<m<<"^"<<flag;
			mark=1;
		}
		i++;flag--;
	}
	return 0;
}










