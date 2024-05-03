#include<bits/stdc++.h>
using namespace std;
int n,a[1010],b[1010]; //a[]阶乘  b[]阶乘和 
int main(){
	cin>>n;
	a[1]=1;int len=1;
	for(int i=1;i<=n;i++){
		//求阶乘
		len=1;a[1]=1;
		for(int j=1;j<=i;j++){
			int flag=0;
			for(int k=1;k<=len;k++){
				a[k]=a[k]*j+flag;
				flag=a[k]/10;
				a[k]%=10;
			}
			while(flag){
				a[++len]=flag%10;
				flag/=10;
			}
		} 
		
		//求阶乘的和  b[]=b[]+a[]]
		int flag=0;
		for(int j=1;j<=len;j++){
			b[j]=b[j]+a[j]+flag;
			flag=b[j]/10;
			b[j]%=10;
		}
		if(flag>0) b[++len]=flag;
	}
	
	for(int i=len;i>0;i--) cout<<b[i];
	
//	long long ans=0,res=1;
//	for(int i=1;i<=n;i++){
//		res=1;
//		for(int j=1;j<=i;j++) res=res*j;   //求i!  要改成 高精度*高精度 
//		cout<<i<<"!"<<":"<<res<<endl;
//		ans+=res;  //求阶乘和  要改成高精度+高精度 
//		
//	}
//	cout<<ans;

	return 0;
} 
