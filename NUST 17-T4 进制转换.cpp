#include<bits/stdc++.h>
using namespace std;
//������Bar �˽���Oct��ʮ����Decimal��ʮ������BE��ʮ������Hex

//ʮ����ת�����Ƶķ���
void DecToBarFun1(int Dec_x){
	bitset<10> bit(Dec_x);  //bitset����Ϊ�����Ƶı���λ�� 
	cout<<bit<<endl;
} 

//ʮ����ת������ �ǵݹ� ��ѭ��Ҳ����
void  DecToBarFun2(int Dec_x){
	string res;
	while(Dec_x!=0){
		res = (Dec_x %2 == 0 ?"0":"1") + res;
		Dec_x/=2;
	}
	cout<<res;
}

//ʮ����ת�˽��� �ǵݹ� ��ѭ��Ҳ����
void DecToOct(int Dec_x){
	string res;
	while(Dec_x!=0){
		res = to_string(Dec_x%8) + res;
		Dec_x/=8;
	}
	cout<<res;
}

//ʮ����ת�κν��Ƶ�ͨ��ԭʼ����  Ҫ�õ��ݹ� ������� 
void GeneralDecToOther(int Dec_x,int r){
	if(Dec_x>0){
		GeneralDecToOther(Dec_x/r,r);
		if(r<16) cout<<Dec_x%r; //16����Ҫ��������A,B,C�� 
		else if(r==16){
			int c = Dec_x%r;
			char ch;
			if(c>9){
				ch = c-10+'A';cout<<ch; 
			}else{
				cout<<c;
			}
		}
	} 
}

int main(){
	//test:
//	int test1=97;char test2= 'A';
//	cout<<char(test1)<<endl;  //a
//	int test3=test2+2;  //67  'A'Ϊ65 
//	char test4=test2+2;  //C
//	cout<<test3<<" "<<test4<<endl;

	//NUST����-�ο��㷨����
	int n;cin>>n;
	GeneralDecToOther(n,2);cout<<endl;
	GeneralDecToOther(n,8);cout<<endl;
	GeneralDecToOther(n,16);cout<<endl; 
	
	//DecToBarFun1(n);
	//DecToBarFun2(n);
	//DecToOct(n);
	
	return 0;
}






