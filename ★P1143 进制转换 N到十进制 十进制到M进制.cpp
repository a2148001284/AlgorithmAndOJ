#include<bits/stdc++.h>
using namespace std;
//����ת�����ȶ�ת��ʮ���� ��ʮ����ת���������� 
int n,m;string res;int sum=0;
void ToDec(){
	for(int i=0;i<res.length();i++){
		if(res[i]<'A') sum+=(res[i]-'0')*pow(n,res.length()-i-1);
		else sum+=(res[i]-'A'+10)*pow(n,res.length()-i-1);
	}
	//sumΪʮ����ת�����ֵ 
	//cout<<"sum:"<<sum<<endl;
}
void ToOther(int x,int r){
	if(x>0){
		ToOther(x/r,r);
		if(r<=10) cout<<x%r;  //if(r<16) cout<<x%r;
		else if(r>10){    //else if(r==16){
			int c=x%r;char ch;
			if(c>9) ch=c+'A'-10,cout<<ch;
			else cout<<c;
		}
	}
}
int main(){
	scanf("%d",&n);cin>>res;scanf("%d",&m);
	ToDec();
	ToOther(sum,m);
	return 0;
}
