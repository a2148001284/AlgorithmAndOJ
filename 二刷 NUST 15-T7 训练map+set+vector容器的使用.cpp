#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>//���ٵ�����Ԫ�� 
#include<set>//һ��Ԫ�� Ҳ������pair������� 
#include<vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;//�ݼ����� 
}
int main(){
	//set<pair<int,int>> a;
	map<int,int> mp;
	while(1){
		int x;scanf("%d",&x);if(x==-1) break;
		mp[x]++;
	}
	//map���������� ��vector
	//map�ķ��ʿ���ֱ�������鷽ʽ ��pair�ķ�����.first ��.second 
	//ʹ�õ��������Ժ� ����һ��ʹ��->first��->second 
	printf("��Ԫ�ؼ�����ִ���:\n");
	for(map<int,int>::iterator a=mp.begin();a!=mp.end();a++){
		printf("%d:%d",a->first,a->second);a++;
		if(a!=mp.end()) printf(",");a--;
	}
	vector<pair<int,int> >s;
	for(map<int,int>::iterator a=mp.begin();a!=mp.end();a++)
		s.push_back(make_pair(a->first,a->second));
	//������ ����vector��������� ���մ����Ӵ�С���� sortĬ���ǵ��� ��������Ĭ���ǵݼ�
	sort(s.begin(),s.end(),cmp);
	printf("\n������:\n");
	for(vector<pair<int,int>>::iterator a=s.begin();a!=s.end();a++){
		printf("%d:%d",a->first,a->second);
		if(a+1!=s.end()) printf(",");
	}
	return 0;
}
