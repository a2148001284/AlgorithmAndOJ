#include<bits/stdc++.h>
using namespace std;
int a[1010],n;//1<=n<=100
//��������oj 1285 - ����N�Ľ׳�   https://oj.czos.cn/p/1285 
int main(){
	a[1]=1;int len=1;
	cin>>n;
	for(int i=1;i<=n;i++){ 	//a[]=a[]*i  �׳˲��� 
		int flag=0;//��λ
		for(int j=1;j<=len;j++){  //�߾���*�Ǹ߾��� 
			a[j]=a[j]*i+flag;
			flag=a[j]/10;
			a[j]%=10;
		} 
		while(flag){  //�����λ��λ 
			a[++len]=flag%10;
			flag/=10;
		}	
	}
	for(int i=len;i>=1;i--) cout<<a[i];
	return 0;	
}
