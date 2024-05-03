#include<bits/stdc++.h>
using namespace std;
int main(){
	
	vector<int> bxy;
	vector<int> lyj[100];
	vector<vector<int>> bxylyj;
	
	bxy.push_back(520); //add
	cout<<bxy[0]<<endl;  //print
	bxy.push_back(1314);
	cout<<bxy[1]<<endl;
	cout<<bxy.size()<<endl;
	bxy.pop_back();//delete
	cout<<bxy.size()<<endl;
	
	bxy.insert(bxy.begin()+1,555);
	cout<<bxy[1]<<endl;
	bxy.erase(bxy.begin()+1);
	cout<<bxy.size()<<endl;
	
}
