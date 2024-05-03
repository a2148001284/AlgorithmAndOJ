#include<bits/stdc++.h>
using namespace std;
int ans=0;int n,x;
void fun(int a){
	while(1){
		int tp=a%10;if(tp==x) ans++;
		a/=10;if(a==0) break;
	}
}
int main(){
	scanf("%d%d",&n,&x);
	for(int i=1;i<=n;i++) fun(i);
	printf("%d",ans);
	return 0;
}
