#include<bits/stdc++.h>
using namespace std;
int coun = 0;
void GetSuShu(int start,int end){
	for(int i=start;i<=end;i++){
		int j;
		for(j=2;j<=sqrt(i);j++){
			if(i%j==0) break;
		} 
		if(j>sqrt(i)){
			coun++;
		}
	}
}
int main(){
	int x,y;cin>>x>>y;
	GetSuShu(x,y);
	cout<<coun;
	return 0;
}







