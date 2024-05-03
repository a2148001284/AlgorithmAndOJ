#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int n,m;int mins=0x3f3f3f3f;int a[3005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int j=1;j<=n-m+1;j++){
		int tmp=0;int tmps=j;
		for(int tmps=j;tmps<=j+m-1;tmps++) tmp+=a[tmps];
		mins=min(mins,tmp);
	}
	printf("%d",mins);
	return 0;
}
