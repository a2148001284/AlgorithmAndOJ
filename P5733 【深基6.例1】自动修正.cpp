#include<bits/stdc++.h>
using namespace std;
int main(){
	string test;
	cin>>test;
	//cout<<char(int(test[2])-32);
	//´óĞ´×ÖÄ¸A-Z:65-90  Ğ¡Ğ´×ÖÄ¸a-z:97-122 ²îÖµÎª32 
	for(int i=0;i<test.length();i++) 
		if(int(test[i])>=97 && int(test[i]<=122)) 
			test[i]=char(int(test[i])-32);
	for(int i=0;i<test.length();i++) cout<<test[i];
	return 0;
}
