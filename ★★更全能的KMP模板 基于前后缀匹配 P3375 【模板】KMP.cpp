#include<bits/stdc++.h>
using namespace std;
//�����ĿҪ�� ��Ҫ���ò�ͬ���±� ��next���������Ŀ����˼
//��ԭ���ķ���(��1��ʼ��) ��2λ�ò�ƥ�� ��Ҫ��ƥ��1λ�� ��next[2]=1
//�����õ�kmp�㷨�Ƿ���ǰ��׺ƥ��ķ������е�(2λ�ò�ƥ�� �����Ϊ0 Ӧ��Ϊ0) ׼ȷ��˵������next���� 
#define MAXN 1000010
char a[MAXN],b[MAXN];int kmp[MAXN]; //��Ҫ�Ŀռ���� ���ܶ�����main�� Ҫômalloc��̬���� Ҫôȫ�ֱ��� 
int la,lb;
int main(){
	cin>>a+1;
	cin>>b+1;
	la=strlen(a+1);
	lb=strlen(b+1);
	//ѭ������ģʽ�� �����ǰ��׺��󳤶� ��kmp���� 
	int i=2,j=0;kmp[1]=0;//iָ����Ǵ�ƥ��λ�� j+1ָ����Ǵ�ƥ��λ�� 
	for(i=2;i<=lb;i++){
		while(j!=0 && b[i]!=b[j+1]) j=kmp[j];
		if(b[i]==b[j+1]) j++; //ƥ��ɹ� 
		kmp[i]=j;
	}
	//�����������kmp����ѭ������ԭ��
	j=0;
	for(int i=1;i<=la;i++){
		while(j!=0 && b[j+1]!=a[i]) j=kmp[j];
		if(b[j+1]==a[i]) j++;
		if(j==lb) printf("%d\n",i-lb+1),j=kmp[j];
	} 
	
	for(int i=1;i<=lb;i++) cout<<kmp[i]<<" ";
	return 0;
}










