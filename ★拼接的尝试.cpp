#include<bits/stdc++.h>
using namespace std;
int main(){
	//1.�ַ���charƴ�ӵĳ���(���㶼��ascii���� ֱ��������Ƕ�Ӧֵ to_string�������ascii��)
	char a='5';char b='6';char c =a+b;char d='A';
	cout<<c<<endl; //k
	cout<<char(a+b)<<endl;//k
	cout<<a+b<<endl; //107  53+54=107   char��ƴ����ASCII������ ���Ϊchar ����תΪchar�� 
	cout<<to_string(a)<<endl;  //53  ˵��char�ڼ��������ASCII����ʽ���� ����to_stringҲ��53
	cout<<to_string(a+b)<<endl; //107
	cout<<to_string(char(a+b))<<endl;  //107
	cout<<to_string(c)<<endl;//107
	cout<<d<<endl; //A
	cout<<a<<endl;//5
	cout<<to_string(d)<<endl;//65
	cout<<a-'0'<<endl; //5   53-48=5
	cout<<a+'0'<<endl; //101
	cout<<a+'3'<<endl; //104
	cout<<a-'3'<<endl;  //2  53-51=2
	
	int e = 3;
	cout<<e+a<<endl; //56 '5'Ϊ53 ����int��char���� ��char��ascii��int���
	cout<<char(e+a)<<endl;  //'8' 
	
	//ƴ�ӷ���  ��ֵ��string ��Ҫ��to_string 
	string tmp_a;tmp_a=a; string tmp_b;tmp_b=b;
	cout<<tmp_a+tmp_b<<endl; //"56"
	
	
	//2.int���͵�ƴ��
	int x=5;int y=6;
	cout<<x+y<<endl;//11
	cout<<to_string(x)+to_string(y)<<endl; //"56"
	
	//3.string����
	string xx = "12345";
	cout<<xx[2]<<endl;//3
	cout<<xx[2]+3<<endl;//54   '3'��asciiΪ51 51+3=54
	cout<<xx[2]+'0'<<endl; //99  51+48=99
	cout<<xx[2]-'0'<<endl; //51-48=3 ������Ϊ���� 
	cout<<8+xx[1]-'0'<<endl; //10
	int aaa;aaa=8+xx[1]-'0';cout<<aaa<<endl; //10
	//str char string�е����� ͨ��-'0' ����ת�������� 
	 
	
	return 0; 
}
