#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#include<map>//至少的两个元素 
#include<set>//一个元素 也可以用pair变成两个 
#include<vector>
using namespace std;
bool cmp(pair<int,int> a,pair<int,int> b){
	return a.second>b.second;//递减排序 
}
int main(){
	//set<pair<int,int>> a;
	map<int,int> mp;
	while(1){
		int x;scanf("%d",&x);if(x==-1) break;
		mp[x]++;
	}
	//map不可以排序 用vector
	//map的访问可以直接用数组方式 而pair的访问是.first 和.second 
	//使用到迭代器以后 访问一律使用->first和->second 
	printf("各元素及其出现次数:\n");
	for(map<int,int>::iterator a=mp.begin();a!=mp.end();a++){
		printf("%d:%d",a->first,a->second);a++;
		if(a!=mp.end()) printf(",");a--;
	}
	vector<pair<int,int> >s;
	for(map<int,int>::iterator a=mp.begin();a!=mp.end();a++)
		s.push_back(make_pair(a->first,a->second));
	//接下来 放入vector后进行排序 按照次数从大到小排序 sort默认是递增 而堆排序默认是递减
	sort(s.begin(),s.end(),cmp);
	printf("\n排序结果:\n");
	for(vector<pair<int,int>>::iterator a=s.begin();a!=s.end();a++){
		printf("%d:%d",a->first,a->second);
		if(a+1!=s.end()) printf(",");
	}
	return 0;
}
