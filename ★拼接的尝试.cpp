#include<bits/stdc++.h>
using namespace std;
int main(){
	//1.字符串char拼接的尝试(运算都是ascii运算 直接输出才是对应值 to_string都是输出ascii码)
	char a='5';char b='6';char c =a+b;char d='A';
	cout<<c<<endl; //k
	cout<<char(a+b)<<endl;//k
	cout<<a+b<<endl; //107  53+54=107   char的拼接是ASCII码的相加 如果为char 则再转为char型 
	cout<<to_string(a)<<endl;  //53  说明char在计算机中以ASCII的形式存在 所以to_string也是53
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
	cout<<e+a<<endl; //56 '5'为53 所以int和char计算 是char的ascii和int相加
	cout<<char(e+a)<<endl;  //'8' 
	
	//拼接方法  赋值给string 不要用to_string 
	string tmp_a;tmp_a=a; string tmp_b;tmp_b=b;
	cout<<tmp_a+tmp_b<<endl; //"56"
	
	
	//2.int类型的拼接
	int x=5;int y=6;
	cout<<x+y<<endl;//11
	cout<<to_string(x)+to_string(y)<<endl; //"56"
	
	//3.string类型
	string xx = "12345";
	cout<<xx[2]<<endl;//3
	cout<<xx[2]+3<<endl;//54   '3'的ascii为51 51+3=54
	cout<<xx[2]+'0'<<endl; //99  51+48=99
	cout<<xx[2]-'0'<<endl; //51-48=3 运算结果为整形 
	cout<<8+xx[1]-'0'<<endl; //10
	int aaa;aaa=8+xx[1]-'0';cout<<aaa<<endl; //10
	//str char string中的数字 通过-'0' 可以转换成整形 
	 
	
	return 0; 
}
