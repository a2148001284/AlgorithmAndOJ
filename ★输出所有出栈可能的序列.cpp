#include<queue>
#include<stack>
#include<iostream>
using namespace std;
//������push front pop   ջ��top push pop 
void dfs(stack<int>s,queue<int>qin,queue<int>qout){  //�ݹ�������е����� 
	if(qin.empty()){  //��������Ѿ�Ϊ�� 
		if(s.empty()){ //ջҲ�Ѿ�Ϊ�� ��ʾ��� 
			while(!qout.empty()){
				cout<<qout.front()<<" ";
				qout.pop();
			}
			cout<<endl;
		}else{  //ջ�ڻ������� ��ʱΨһ��ѡ����ǳ�ջ 
			while(!s.empty()){
				qout.push(s.top());
				s.pop();
			}
			dfs(s,qin,qout);//��ջ��Ϻ����dfs�������		
		} 
	}else{  //������л���Ϊ�� 
		if(s.empty()){  //��ʱջ�Ѿ�Ϊ�� ���еĲ���ֻ�У���ջ 
			s.push(qin.front());qin.pop();
			dfs(s,qin,qout);
		}else{  //��ʱջ����Ϊ�� ���У�1.��ջ 2.��ջ 
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
	queue<int> qin,qout;//������к��������
	stack<int> s;//ջ
	int n,x;cin>>n;//��ʾn��ԭʼ��
	while(n--){
		cin>>x;qin.push(x);//����д��qin������� 
	} 
	dfs(s,qin,qout);
	return 0;
}





