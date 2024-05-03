#include<bits/stdc++.h>
using namespace std;
int n;map<string,bool>targ;int sum;
//想得到就很简单 想不到就很复杂 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		string tmp;cin>>tmp;//getline(cin,tmp); getline会默认读取空格 只有回车为结束符 后续数据太大 可能没有换行 
		sort(tmp.begin(),tmp.end());
		if(targ[tmp]==false) sum++,targ[tmp]=true;
	}
	printf("%d",sum);
	return 0;
}









