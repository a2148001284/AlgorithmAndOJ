#include<bits/stdc++.h>
using namespace std;
//结合题目要求 需要设置不同的下标 让next数组符合题目的意思
//且原来的方法(从1开始存) 若2位置不匹配 会要求匹配1位置 即next[2]=1
//本题用的kmp算法是符合前后缀匹配的方法进行的(2位置不匹配 则个数为0 应置为0) 准确来说不算是next数组 
#define MAXN 1000010
char a[MAXN],b[MAXN];int kmp[MAXN]; //需要的空间过大 不能定义在main内 要么malloc动态分配 要么全局变量 
int la,lb;
int main(){
	cin>>a+1;
	cin>>b+1;
	la=strlen(a+1);
	lb=strlen(b+1);
	//循环处理模式串 获得其前后缀最大长度 求kmp数组 
	int i=2,j=0;kmp[1]=0;//i指向的是待匹配位置 j+1指向的是待匹配位置 
	for(i=2;i<=lb;i++){
		while(j!=0 && b[i]!=b[j+1]) j=kmp[j];
		if(b[i]==b[j+1]) j++; //匹配成功 
		kmp[i]=j;
	}
	//接下来用这个kmp数组循环处理原串
	j=0;
	for(int i=1;i<=la;i++){
		while(j!=0 && b[j+1]!=a[i]) j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==lb) printf("%d\n",i-lb+1),j=kmp[j];
	} 
	
	for(int i=1;i<=lb;i++) cout<<kmp[i]<<" ";
	return 0;
}










