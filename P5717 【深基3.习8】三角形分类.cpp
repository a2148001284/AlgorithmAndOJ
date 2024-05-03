#include<bits/stdc++.h>
using namespace std;
int main(){
	int aa[3];cin>>aa[0]>>aa[1]>>aa[2];
	sort(aa,aa+3);
	int a=aa[0];int b=aa[1];int c=aa[2];
	//当两短边的平方和大于一长边的平方，说明是锐角三角形。
	//当两短边的平方和等于一长边的平方，说明是直角三角形。
	//当两短边的平方和小于一长边的平方，说明是钝角三角形。
	if(a+b<=c) cout<<"Not triangle";
	else{  //必须用else 有可能构不成三角形 但是有a=b的情况 
		if(a*a+b*b==c*c) cout<<"Right triangle"<<endl;
		if(a*a+b*b>c*c) cout<<"Acute triangle"<<endl;  //锐角应该是a*a+b*b>c*c 
		if(a*a+b*b<c*c) cout<<"Obtuse triangle"<<endl;//钝角应该是a*a+b*b<c*c 
		if(a==b || a==c || b==c) cout<<"Isosceles triangle"<<endl;  
		//Error:a==b!=c  而且等腰只要腰相等就行 不用不等于第三条边 Error:a==b && b!=c 
		if(a==b && b==c) cout<<"Equilateral triangle"; //Error:a==b==c
	}
	return 0;
}
