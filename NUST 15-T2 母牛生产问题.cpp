#include<iostream>
#include<string>
using namespace std;
//1 1 1 2 3 4 6 9 13 19 28 41 60 88 129 189 277 406 595 872
int dp[21];//���仯�����Ż� 
int cow(int year) {
	if(dp[year]!=0) return dp[year];
	if(year<=3)  //ĸţ�ӵ����꿪ʼ��������ǰ����ĸţ������Ϊ1ͷ
		dp[year]=1;
	else
		dp[year]=cow(year-1)+cow(year-3);  //�ݹ���ĸţ������
	return dp[year];
}

int main() {
	fill(dp,dp+21,0);
	for (int i=1; i<=20; i++) {  //������ݣ�����ӵ�һ�굽��20���ĸţ����
		cout<<cow(i)<<" ";
	}
	//�Ż�ǰ: 0.02744s
	//�Ż���: 0.02601s
}







