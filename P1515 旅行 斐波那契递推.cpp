#include<bits/stdc++.h>
using namespace std;
int lists[50]={0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int ans[50];
int A,B,N;
/*
1.һ�����鴢�������ùݣ���ʼ��ʱ�ȴ���ǰ��14���ùݡ�
2.����������ùݺ󣬽������ù����򣬷����պ�Ƚϡ�
3.����쳲��������У�������Դ�A���ߵ�B�㣬��ôA����ܷ�����Ӧ�ü���B��ķ�������
4.ѭ������3�������ɣ���B��ֻ��Ҫ��A��ǰ��ĵ㣩��
*/ 
int main(){
	scanf("%d%d%d",&A,&B,&N);
	if(N>=1) for(int i=14;i<=13+N;i++) scanf("%d",&lists[i]);
	sort(lists,lists+14+N);//�ùݾ����С�������
	ans[0]=1;
	for(int i=1;i<=13+N;i++) //쳲�����˼����� 
		for(int j=0;j<i;j++){
			if(lists[j]+A<=lists[i] && lists[j]+B>=lists[i]){
				ans[i]+=ans[j];
			}
		}
	cout<<ans[13+N]<<endl;
	return 0;
}







