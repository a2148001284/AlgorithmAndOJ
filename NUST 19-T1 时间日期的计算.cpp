#include<bits/stdc++.h>
using namespace std;
bool JudgeYear(int year){
	if((year%4==0 && year%100 !=0) || year%400 == 0) return true;
	else return false;
}

int main(){
	string week[7] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Satruday","Sunday"};
	int init_year = 2000;int init_month = 1;int init_day = 1;
	int n;cin>>n; 
	int final_week = (n+5)%7; //找规律得出的结果 
	int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
	int days=1;
	while(n>0){
		days++;n--;//天数+1 
		if(days>day[init_month]){  //月份到了 
			if(init_month==2 && days==29 && JudgeYear(init_year)) continue; //闰年29天 
			else{
				days=1;init_month++;
				if(init_month>12){ //月份到了 要增加年份了 
					init_month=1;
					init_year++;
				}
			}
		}
	}
	cout<<init_year<<"/"<<init_month<<"/"<<days<<" "<<week[final_week];
	return 0;
}




