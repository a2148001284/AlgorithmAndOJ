#include<iostream>
using namespace std;
void Opera(){
	string a;cin>>a;char tmp=a[0];int count=0;int maxcount=0;
	for(int i=0;i<int(a.length());i++){
		if(a[i]==tmp){
			maxcount++;
			//cout<<"tmp:"<<tmp<<" maxcount:"<<maxcount<<endl;
		}
		//ISDHFSHFDAASDIAHSD
		 
		else{
			count=max(count,maxcount);
			maxcount=1;tmp=a[i];
		}
		//cout<<"maxcount"<<maxcount<<endl;
	}
	count=max(count,maxcount);
	cout<<count<<endl;
}
int main(){
	int n;cin>>n;
	while(n--) Opera();
	return 0;
}
