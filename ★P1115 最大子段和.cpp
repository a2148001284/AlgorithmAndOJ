#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/**P1115 最大子段和 算法详细分析 
 * 第一个数为一个有效序列
 *如果一个数加上上一个有效序列得到的结果比这个数大，那么该数也属于这个有效序列。
 *如果一个数加上上一个有效序列得到的结果比这个数小，那么这个数单独成为一个新的有效序列
 *在执行上述处理的过程中实时更新当前有效序列的所有元素之和并取最大值。 
 **/
 void Fun1(){
 	int n,a[200005],b[200005];int ans=-INF;
 	cin>>n;
 	// b[i] 表示截止到 i 时，第 i 个数所在的有效序列的元素和
  	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(i==1) b[i]=a[i];
 		else b[i]=max(a[i],a[i]+b[i-1]);
 		ans = max(ans,b[i]);	 	
 	}
 	cout<<ans;
 }
 
 void Fun2Upgrade(){ //针对fun1 进行空间的优化 
 	int n;cin>>n;int tmp,b;int ans=-INF;
 	for(int i=1;i<=n;i++){
	 	cin>>tmp;
	 	if(i==1) b=tmp;
	 	else b=max(tmp,tmp+b);
	 	ans=max(ans,b);
	 }
	 cout<<ans;
 }
 int main(){
 	//Fun1(); //37ms 1.91MB 空间复杂度高 
 	Fun2Upgrade(); //680KB 36ms
	return 0;
 } 
 
 
 
 
 
 
 
 
