#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
	double s;scanf("%lf",&s);int step=1;double now=2.0;double last_dis=2.0;
	while(1){
		if(now>=s){
			printf("%d",step);return 0;
		} else{
			step++;last_dis=last_dis*0.98;now+=last_dis;
		}
	}
	return 0;
}



