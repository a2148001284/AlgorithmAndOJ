#include<bits/stdc++.h>
#define MAXV 105
using namespace std;
int a[MAXV];int counts=0;int counts2=0;
//�����������Ż��㷨 1-100 
void Get(){
	for(int i=2;i<=100;i+=1){
		int j;
		for(j=2;j<=sqrt(i);j++){ //�ж����� 
			if(i%j==0) break;
		}
		if(j>sqrt(i)) a[counts++]=i;
	}
}
void Opt(){
	for(int i=1;i<counts;i++){
		if(a[i]-a[i-1]==2){
			printf("%d-%d",a[i-1],a[i]);counts2++;cout<<endl;
		}
	}
	cout<<"num:"<<counts2;
}
int main(){
	fill(a,a+MAXV,0);
	Get();
	Opt();
	return 0;
}
