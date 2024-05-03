#include<stack>
#include<queue>
#include<iostream>
using namespace std;
void dfs(queue<char>qin,queue<char>qout,stack<char>s){
	if(qin.empty()){
		if(s.empty()){
			while(!qout.empty()){
				cout<<qout.front()<<" ";
				qout.pop();
			}
			cout<<endl;
		}else{
			while(!s.empty()){
				qout.push(s.top());
				s.pop();
			}
			dfs(qin,qout,s);
		}
	}else{
		if(s.empty()){
			s.push(qin.front());qin.pop();
			dfs(qin,qout,s);
		}else{
			stack<char>tmp_s=s;queue<char>tmp_qin=qin;queue<char>tmp_qout=qout;
			s.push(qin.front());qin.pop();
			dfs(qin,qout,s);
			tmp_qout.push(tmp_s.top());tmp_s.pop();
			dfs(tmp_qin,tmp_qout,tmp_s);
		}
	}
}

#define MAXN 100
long long dp[MAXN][MAXN];int n;
int DpGetTotal(int x,int y){  //ͨ�����仯�������ܹ��ж����ֿ���  x:���� y:ջ 
	if(dp[x][y]) return dp[x][y]; 
	if(x==0) return 1;
	if(y>0) dp[x][y]+=DpGetTotal(x,y-1);
	dp[x][y]+=DpGetTotal(x-1,y+1);
	return dp[x][y];
}
int main(){
	//���Բ��� 
//	char a = 'a'; //'a'��asciiΪ97  
//	cout<<a+2<<endl;  //99
//	cout<<char(a+2)<<endl;  //c
//	cout<<char(int(a)+2)<<endl; //c
	
	queue<char>qin;queue<char>qout;stack<char>s;
	char temp='a';cin>>n;
	//dp��������
	cout<<DpGetTotal(n,0)<<endl;
	while(n--){
		qin.push(temp);temp=char(temp+1);
	}
	dfs(qin,qout,s);
	return 0; 
}



