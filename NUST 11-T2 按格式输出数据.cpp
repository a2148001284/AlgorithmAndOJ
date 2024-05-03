#include<bits/stdc++.h>
using namespace std;
bool compare(int a,int b){
	return a>b;
}
int main(){
	int m;cin>>m;
	int lists[m+1][m+1];
	int res[2*m+2]={0}; //1->m行 m+1->2m列 2m+1主对角线  0不用 
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			cin>>lists[i][j];
			res[i]+=lists[i][j];
			res[m+j]+=lists[i][j];
			if(i==j) res[2*m+1]+=lists[i][j];
		}
	sort(res+1,res+2*m+2,compare);  //res[1]->res[2*m+1] 
	for(int i=1;i<=2*m+1;i++) cout<<res[i]<<" ";
	cout<<endl;
	return 0;
}
