#include<bits/stdc++.h>
using namespace std;
int a[1010],n;//1<=n<=100
//东方博宜oj 1285 - 计算N的阶乘   https://oj.czos.cn/p/1285 
int main(){
	a[1]=1;int len=1;
	cin>>n;
	for(int i=1;i<=n;i++){ 	//a[]=a[]*i  阶乘部分 
		int flag=0;//进位
		for(int j=1;j<=len;j++){  //高精度*非高精度 
			a[j]=a[j]*i+flag;
			flag=a[j]/10;
			a[j]%=10;
		} 
		while(flag){  //处理多位进位 
			a[++len]=flag%10;
			flag/=10;
		}	
	}
	for(int i=len;i>=1;i--) cout<<a[i];
	return 0;	
}
