#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int BubbleSort(int a[],int len){
	bool flag;int ans=0;
	for(int i=0;i<len-1;i++){ //一共要进行len-1趟的排序 
		flag=false;//表明本轮是否发生了交换 
		for(int j=len-1;j>i;j--){
			if(a[j-1]>a[j]){
				swap(a[j],a[j-1]);flag=true;ans++;
			}
		}
		if(flag==false) break;
	}
	return ans;
}
int main(){
	int n;scanf("%d",&n);int a[n];
	for(int i=0;i<n;i++) scanf("%d",&a[i]);
	printf("%d",BubbleSort(a,n));
	return 0;
}





