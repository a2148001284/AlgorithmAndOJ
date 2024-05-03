#include<queue>
#include<stack>
#include<iostream>
using namespace std;
//队列有push front pop   栈有top push pop 
void dfs(stack<int>s,queue<int>qin,queue<int>qout){  //递归输出可行的序列 
	if(qin.empty()){  //输入队列已经为空 
		if(s.empty()){ //栈也已经为空 表示完成 
			while(!qout.empty()){
				cout<<qout.front()<<" ";
				qout.pop();
			}
			cout<<endl;
		}else{  //栈内还有数据 此时唯一的选择就是出栈 
			while(!s.empty()){
				qout.push(s.top());
				s.pop();
			}
			dfs(s,qin,qout);//出栈完毕后继续dfs用于输出		
		} 
	}else{  //输入队列还不为空 
		if(s.empty()){  //此时栈已经为空 可行的操作只有：入栈 
			s.push(qin.front());qin.pop();
			dfs(s,qin,qout);
		}else{  //此时栈还不为空 可行：1.出栈 2.入栈 
			queue<int>temp_qin=qin,temp_qout=qout;
			stack<int>temp_s=s;
			//choice-1
			qout.push(s.top());s.pop();
			dfs(s,qin,qout);
			//choice-2
			temp_s.push(temp_qin.front());
			temp_qin.pop();
			dfs(temp_s,temp_qin,temp_qout);
		}
	}
}   

int main(){
	queue<int> qin,qout;//输入队列和输出队列
	stack<int> s;//栈
	int n,x;cin>>n;//表示n个原始数
	while(n--){
		cin>>x;qin.push(x);//数据写入qin输入队列 
	} 
	dfs(s,qin,qout);
	return 0;
}





