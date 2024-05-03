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
	int x = 8-hour;
	if(x<0){   //x=0时 用的是24点 可能题目是00:xx 所以可以试着不写等号 
		x=x+24;
	}
	printf("%02d:%02d",x,60-other);
	return 0;
}

