#include<bits/stdc++.h>
using namespace std;
int x,n;
//原来用的方法试图找规律 但是并不实际 其实可以直接循环 似乎是因为没有理解题目的意思 
//int gettarg(int sum1,int sum2){
//	if(sum1+sum2<=5) return sum2+1;
//	else if(sum1+sum2==6) return sum2;
//	else if(sum1+sum2>=7 && x!=7) return sum2-1;
//	else if(x==7 && sum1+sum2>7) return sum2;
//}
int main(){
	scanf("%d%d",&x,&n);
//	int t1 = (n/7)*5;
//	int t2=n%7;
//	int t3=gettarg(x,t2);
//	long long sum=(t1+t3)*250;
//	printf("%lld",sum);
//	return 0;
	int sum=0;//表示总和
	for(int i=1;i<=n;i++){ //为什么在里面x++ 一开始不加 理解题目：过了多少天 那一天是不算了 周三过了一天到周四 才游了250 
		//cout<<"当前i:"<<i<<" 当前x:"<<x<<endl;
		if(x!=6 && x!=7) sum+=250;
		if(x==7) x=1;
		else x++; 
	} 
	printf("%d",sum);
	return 0; 
}



