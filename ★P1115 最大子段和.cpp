#include<bits/stdc++.h>
using namespace std;
#define INF INT_MAX
/**P1115 ����Ӷκ� �㷨��ϸ���� 
 * ��һ����Ϊһ����Ч����
 *���һ����������һ����Ч���еõ��Ľ�������������ô����Ҳ���������Ч���С�
 *���һ����������һ����Ч���еõ��Ľ���������С����ô�����������Ϊһ���µ���Ч����
 *��ִ����������Ĺ�����ʵʱ���µ�ǰ��Ч���е�����Ԫ��֮�Ͳ�ȡ���ֵ�� 
 **/
 void Fun1(){
 	int n,a[200005],b[200005];int ans=-INF;
 	cin>>n;
 	// b[i] ��ʾ��ֹ�� i ʱ���� i �������ڵ���Ч���е�Ԫ�غ�
  	for(int i=1;i<=n;i++){
 		cin>>a[i];
 		if(i==1) b[i]=a[i];
 		else b[i]=max(a[i],a[i]+b[i-1]);
 		ans = max(ans,b[i]);	 	
 	}
 	cout<<ans;
 }
 
 void Fun2Upgrade(){ //���fun1 ���пռ���Ż� 
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
 	//Fun1(); //37ms 1.91MB �ռ临�Ӷȸ� 
 	Fun2Upgrade(); //680KB 36ms
	return 0;
 } 
 
 
 
 
 
 
 
 
