#include<bits/stdc++.h>
using namespace std;
//void test(){
//	//cin�ÿո�/�հ������� ��ǰ��Ŀո񲻻ᱻʶ�� 
//	char a[10];string b;  //  abc 111
//	scanf("%s",a);
//	cin>>b;  
//	cout<<a<<endl;  //abc
//	cout<<b<<endl;  //111
//}
int main(){
	//���� ���ǻ�TLE ����ʹ��string��ķ��� ���ߣ��Ż��� ���β��оͿ��´ε��� �����ǰ����� 
	char a[1000005];char b[11];int flag=1;int ans=0;int first=0;
	//test();
	//Ϊ�˾�ȷƥ�� ����Ҫ�����ߵ�ͷβ���ӿո�ſ���
	//cin.getline(b,11);cin.getline(a,1000005); ���� ����Ҫ�ӿո�
	b[0]=' ';a[0]=' ';
	gets(b+1);gets(a+1);//cin.getline(b+1,11);cin.getline(a+1,1000005);
	strcat(a," ");strcat(b," "); //b[strlen(b)]=' ';a[strlen(a)]=' ';
	//cout<<strlen(a)<<" "<<strlen(b)<<endl; 
	for(int i=0;i<strlen(a);i++) a[i]=tolower(a[i]);
	for(int j=0;j<strlen(b);j++) b[j]=tolower(b[j]);
	//cout<<a<<endl<<b<<endl;
	//cout<<strlen(a)<<" "<<strlen(b)<<endl; ����û������ 
	for(int i=0;i<strlen(a);i++){
		if(a[i]==' ' && a[i+1]!=' '){
			int index=0,j;
			for(j=i;j<i+strlen(b);j++) if(a[j]!=b[index++]) break;
			if(j==i+strlen(b)){
				ans++;
				if(flag){
					first=i;flag=0;
				}
			}	
		}	
	}
	if(ans>0) printf("%d %d",ans,first);
	else printf("-1");
	return 0;
}






