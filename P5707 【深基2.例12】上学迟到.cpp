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
	if(x<0){   //x=0ʱ �õ���24�� ������Ŀ��00:xx ���Կ������Ų�д�Ⱥ� 
		x=x+24;
	}
	printf("%02d:%02d",x,60-other);
	return 0;
}

