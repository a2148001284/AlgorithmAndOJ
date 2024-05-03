#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000
int n,m;int a[MAXN];
void A_oper(){
	//cout<<"this A"<<endl; 
	int x;cin>>x;
	n++;a[n-1]=x;
}
void I_oper(){
	//cout<<"this I"<<endl; 
	int i,aa;cin>>i>>aa;int t;
	for(t=n;t>=i-1;t--) a[t+1]=a[t];
	a[++t]=aa;n++;
}

void Q_oper(){
	//cout<<"this Q"<<endl; 
	int i;cin>>i;int count=0;
	for(int j=0;j<n;j++)
		if(a[j]==i) count++;
	cout<<count<<"\n";
}

void P_oper(){
	//cout<<"this P"<<endl; 
	for(int i=0;i<n;i++) cout<<a[i]<<" ";
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	int num;cin>>num;
	while(num--){
		//cout<<"this"<<endl; 
		char Sign;cin>>Sign;
		if(Sign == 'A') A_oper();
		else if(Sign == 'I') I_oper();
		else if(Sign == 'Q') Q_oper();
		else if(Sign == 'P') P_oper();
	}
	return 0;
}
