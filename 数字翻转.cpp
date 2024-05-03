#include<bits/stdc++.h>
using namespace std;
int main(){
	double distance,speed;
	cin>>distance>>speed;
	int time = ceil(distance/speed);
	time += 10;
	int hour = time / 60;
	int other = time % 60;
	if(other != 0){
		hour+=1;
	}
	printf("%02d:%02d",8-hour,60-other);
	
}

