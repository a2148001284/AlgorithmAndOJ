#include<bits/stdc++.h>
using namespace std;
int main(){
	int x;cin>>x;
	if(x==1) cout<<"Today, I ate 1 apple.";
	else if(x==0) cout<<"Today, I ate 0 apple.";
	//else cout<<"Today, I ate "+to_string(x)+" apples.";
	else cout<<"Today, I ate "<<x<<" apples.";
	return 0;
}
