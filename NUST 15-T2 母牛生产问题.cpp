#include<iostream>
#include<string>
using namespace std;
//1 1 1 2 3 4 6 9 13 19 28 41 60 88 129 189 277 406 595 872
int dp[21];//记忆化搜索优化 
int cow(int year) {
	if(dp[year]!=0) return dp[year];
	if(year<=3)  //母牛从第三年开始生产，则前两年母牛的数量为1头
		dp[year]=1;
	else
		dp[year]=cow(year-1)+cow(year-3);  //递归求母牛的数量
	return dp[year];
}

int main() {
	fill(dp,dp+21,0);
	for (int i=1; i<=20; i++) {  //遍历年份，输出从第一年到第20年的母牛数量
		cout<<cow(i)<<" ";
	}
	//优化前: 0.02744s
	//优化后: 0.02601s
}







