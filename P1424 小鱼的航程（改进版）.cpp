#include<bits/stdc++.h>
using namespace std;
int x,n;
//ԭ���õķ�����ͼ�ҹ��� ���ǲ���ʵ�� ��ʵ����ֱ��ѭ�� �ƺ�����Ϊû�������Ŀ����˼ 
//int gettarg(int sum1,int sum2){
//	if(sum1+sum2<=5) return sum2+1;
//	else if(sum1+sum2==6) return sum2;
//	else if(sum1+sum2>=7 && x!=7) return sum2-1;
//	else if(x==7 && sum1+sum2>7) return sum2;
//}
int main(){
	scanf("%d%d",&x,&n);
//	int t1 = (n/7)*5;
//	int t2=n%7;
//	int t3=gettarg(x,t2);
//	long long sum=(t1+t3)*250;
//	printf("%lld",sum);
//	return 0;
	int sum=0;//��ʾ�ܺ�
	for(int i=1;i<=n;i++){ //Ϊʲô������x++ һ��ʼ���� �����Ŀ�����˶����� ��һ���ǲ����� ��������һ�쵽���� ������250 
		//cout<<"��ǰi:"<<i<<" ��ǰx:"<<x<<endl;
		if(x!=6 && x!=7) sum+=250;
		if(x==7) x=1;
		else x++; 
	} 
	printf("%d",sum);
	return 0; 
}



