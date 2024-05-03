#include<bits/stdc++.h>
using namespace std;
/*
 比如说40和12，40/12余4，除数作为下一回的被除数，
 余数作为下一回的除数，得到12/4，这就是最大公约数
 （如果有余数就再除，直到没有余数，这正好符合递归思想）
*/
int Gcd(int x,int y){//辗转相除求最大公约数 
	if(x<y) swap(x,y);
	if(x%y==0) return y;
	else return Gcd(y,x%y);
}
//最大公约数和最小公倍数的乘积等于原来两个数乘积
int Lcm(int x,int y){
	return x*y/Gcd(x,y);
}
void Answer1(){
	int x0,y0;cin>>x0>>y0;int ans=0; //ans记得赋值0 否则出错 
	//原来的数必在x0和y0之间
	for(int i=x0;i<=y0;i++){
		int j=x0*y0/i;
		if(Gcd(i,j)==x0 && Lcm(i,j)==y0) ans++;
	} 
	cout<<ans<<endl;
}

void Answer2(){
	long long x0,y0;cin>>x0>>y0;long long ans=0;  //ans记得赋值0 否则出错 
	//如果x0=y0 则P=Q=X0=Y0 那么交换后算重复 要ans-1
	if(x0==y0) ans--;
	y0*=x0;//乘积存到y0里
	for(long long i=1;i<=sqrt(y0);i++)
		if(y0%i==0 && __gcd(i,y0/i)==x0) ans+=2; 
		//c++ 自带gcd可以求出最大公约数 最小公倍数可以不判断 一定成立 
	cout<<ans<<endl;
}

int main(){
	//Answer1();
	Answer2();
	return 0;
}









