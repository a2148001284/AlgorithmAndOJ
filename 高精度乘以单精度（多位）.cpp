#include<bits/stdc++.h>
using namespace std;
//1286 - �߾��ȳ˵�����
//��Դ����������oj   oj.czos.cn
int main(){
	char A[250];//��������������
	int a[250]; int beichengshu;
	cin>>A>>beichengshu;int len=strlen(A);
	for(int i=0;i<len;i++) a[len-i]=A[i]-'0';
	//int len2 = len+1;
	int flag=0;//��ʾ��λ 
	for(int i=1;i<=len;i++){
		a[i]=a[i]*beichengshu+flag;
		flag=a[i]/10;
		a[i]%=10;
	}
	//����ǰ��0
	while(a[len]==0 &&len>1) --len; 
	while(flag){
		a[++len]=flag%10;
		flag/=10;
	} 
	//if(a[len2]==0 && len2>0) len2--;
	for(int i=len;i>0;i--) cout<<a[i];
	return 0; 
}
