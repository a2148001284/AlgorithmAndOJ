#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	int totaltime = (c*60+d) - (a*60+b);
	int hour = totaltime / 60;
	int minutes = totaltime % 60;
	cout<<hour<<" "<<minutes;
}
