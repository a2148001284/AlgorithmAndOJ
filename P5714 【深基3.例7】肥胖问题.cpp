#include<bits/stdc++.h>
using namespace std;
int main(){
	double m,h;
	cin>>m>>h;
	double BMI = m/(h*h);
	if(BMI<18.5) cout<<"Underweight";
	else if(BMI<24) cout<<"Normal";
	else cout<<BMI<<endl<<"Overweight";
	return 0;
}
