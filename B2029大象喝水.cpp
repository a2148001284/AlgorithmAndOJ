#include<bits/stdc++.h>
using namespace std;
#define PI 3.14
int main(){
	int h,r;
	cin>>h>>r; 
	double V = PI*r*r*h*0.001;
	cout<<ceil(20/V);
}
