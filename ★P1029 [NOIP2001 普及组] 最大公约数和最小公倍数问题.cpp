#include<bits/stdc++.h>
using namespace std;
/*
 ����˵40��12��40/12��4��������Ϊ��һ�صı�������
 ������Ϊ��һ�صĳ������õ�12/4����������Լ��
 ��������������ٳ���ֱ��û�������������÷��ϵݹ�˼�룩
*/
int Gcd(int x,int y){//շת��������Լ�� 
	if(x<y) swap(x,y);
	if(x%y==0) return y;
	else return Gcd(y,x%y);
}
//���Լ������С�������ĳ˻�����ԭ���������˻�
int Lcm(int x,int y){
	return x*y/Gcd(x,y);
}
void Answer1(){
	int x0,y0;cin>>x0>>y0;int ans=0; //ans�ǵø�ֵ0 ������� 
	//ԭ����������x0��y0֮��
	for(int i=x0;i<=y0;i++){
		int j=x0*y0/i;
		if(Gcd(i,j)==x0 && Lcm(i,j)==y0) ans++;
	} 
	cout<<ans<<endl;
}

void Answer2(){
	long long x0,y0;cin>>x0>>y0;long long ans=0;  //ans�ǵø�ֵ0 ������� 
	//���x0=y0 ��P=Q=X0=Y0 ��ô���������ظ� Ҫans-1
	if(x0==y0) ans--;
	y0*=x0;//�˻��浽y0��
	for(long long i=1;i<=sqrt(y0);i++)
		if(y0%i==0 && __gcd(i,y0/i)==x0) ans+=2; 
		//c++ �Դ�gcd����������Լ�� ��С���������Բ��ж� һ������ 
	cout<<ans<<endl;
}

int main(){
	//Answer1();
	Answer2();
	return 0;
}









