#include<bits/stdc++.h>
using namespace std;
int main(){
	int aa[3];cin>>aa[0]>>aa[1]>>aa[2];
	sort(aa,aa+3);
	int a=aa[0];int b=aa[1];int c=aa[2];
	//�����̱ߵ�ƽ���ʹ���һ���ߵ�ƽ����˵������������Ρ�
	//�����̱ߵ�ƽ���͵���һ���ߵ�ƽ����˵����ֱ�������Ρ�
	//�����̱ߵ�ƽ����С��һ���ߵ�ƽ����˵���Ƕ۽������Ρ�
	if(a+b<=c) cout<<"Not triangle";
	else{  //������else �п��ܹ����������� ������a=b����� 
		if(a*a+b*b==c*c) cout<<"Right triangle"<<endl;
		if(a*a+b*b>c*c) cout<<"Acute triangle"<<endl;  //���Ӧ����a*a+b*b>c*c 
		if(a*a+b*b<c*c) cout<<"Obtuse triangle"<<endl;//�۽�Ӧ����a*a+b*b<c*c 
		if(a==b || a==c || b==c) cout<<"Isosceles triangle"<<endl;  
		//Error:a==b!=c  ���ҵ���ֻҪ����Ⱦ��� ���ò����ڵ������� Error:a==b && b!=c 
		if(a==b && b==c) cout<<"Equilateral triangle"; //Error:a==b==c
	}
	return 0;
}
