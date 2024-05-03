#include<bits/stdc++.h>
using namespace std;
//二进制Bar 八进制Oct，十进制Decimal，十二进制BE，十六进制Hex

//十进制转二进制的方法
void DecToBarFun1(int Dec_x){
	bitset<10> bit(Dec_x);  //bitset后面为二进制的比特位数 
	cout<<bit<<endl;
} 

//十进制转二进制 非递归 用循环也可以
void  DecToBarFun2(int Dec_x){
	string res;
	while(Dec_x!=0){
		res = (Dec_x %2 == 0 ?"0":"1") + res;
		Dec_x/=2;
	}
	cout<<res;
}

//十进制转八进制 非递归 用循环也可以
void DecToOct(int Dec_x){
	string res;
	while(Dec_x!=0){
		res = to_string(Dec_x%8) + res;
		Dec_x/=8;
	}
	cout<<res;
}

//十进制转任何进制的通用原始方法  要用到递归 逆序输出 
void GeneralDecToOther(int Dec_x,int r){
	if(Dec_x>0){
		GeneralDecToOther(Dec_x/r,r);
		if(r<16) cout<<Dec_x%r; //16进制要单独处理A,B,C等 
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
//	int test3=test2+2;  //67  'A'为65 
//	char test4=test2+2;  //C
//	cout<<test3<<" "<<test4<<endl;

	//NUST机试-参考算法测试
	int n;cin>>n;
	GeneralDecToOther(n,2);cout<<endl;
	GeneralDecToOther(n,8);cout<<endl;
	GeneralDecToOther(n,16);cout<<endl; 
	
	//DecToBarFun1(n);
	//DecToBarFun2(n);
	//DecToOct(n);
	
	return 0;
}






