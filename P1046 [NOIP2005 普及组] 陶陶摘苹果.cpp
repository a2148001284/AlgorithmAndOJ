#include<bits/stdc++.h>
using namespace std;
int a[11];int len;
int main(){
	for(int i=1;i<=10;i++) scanf("%d",&a[i]); scanf("%d",&len);
	len+=30;
	sort(a+1,a+11);
	for(int i=1;i<=10;i++){
		if(a[i]>len){
			printf("%d",i-1);break;
		}
	}
	return 0;
}
