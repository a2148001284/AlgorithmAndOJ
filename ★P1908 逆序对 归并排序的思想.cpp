#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
//P1908 逆序对 基于归并排序的思想 正好可以解决逆序对的问题 
int n;
int a[MAXN],tmp[MAXN];
long long ans=0;//represent the sum
void msort(int start,int end){
	if(start == end) return;
	int mid = (start+end)/2;
	msort(start,mid);msort(mid+1,end);
	int i = start,e = mid+1;int k=start;
	while(i<=mid && e<=end){
		if(a[i]<=a[e]) tmp[k++]=a[i++];
		else{
			tmp[k++]=a[e++];ans+=mid-i+1;
		}
	}
	while(i<=mid) tmp[k++]=a[i++];
	while(e<=end) tmp[k++]=a[e++];
	for(int t=start;t<=end;t++) a[t]=tmp[t];
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	msort(1,n);
	printf("%lld",ans);
	return 0;
}









