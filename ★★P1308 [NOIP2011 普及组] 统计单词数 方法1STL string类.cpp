#include<bits/stdc++.h>
using namespace std;
//ʹ��STL��string����в��� 
int main(){
	string init;string targ;
	getline(cin,targ);getline(cin,init);
	//isupper���ж��Ƿ��Ǵ�д��ĸ��ϵͳ������tolower�ǽ���ת����Сд��ĸ�ĺ��� toupper��ת��д 
	for(int i=0;i<init.length();i++) init[i]=tolower(init[i]);
	for(int j=0;j<targ.length();j++) targ[j]=tolower(targ[j]);
	//��������Ҫ�����������ȫƥ��  ����ƥ�䲿�� ����Ҫ��β�ӿո� �ո�����Ҫ��ͬ
	init=' '+init+' ';
	targ=' '+targ+' '; 
	if(init.find(targ)==string::npos){
		printf("-1");
	}else{
		int ans=0;
		//��Ҫ����д ����� ��������������д���� 
		//int first_pos,first_pos2=init.find(targ);cout<<first_pos<<" "<<first_pos2<<endl; //8 0
		int first_pos=init.find(targ);int first_pos2=init.find(targ);//cout<<first_pos<<" "<<first_pos2<<endl; 0 0
		while(first_pos2 != string::npos){
			ans++;first_pos2=init.find(targ,first_pos2+1);//find�ҵ����ǵ�һ�γ��ֵ�λ�� +1���ܼ��� 
		}
		printf("%d %d",ans,first_pos);
	}
	return 0;
} 








