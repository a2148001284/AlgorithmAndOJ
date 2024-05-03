#include<bits/stdc++.h>
using namespace std;
typedef char DataType;
struct LNode{
	DataType data;
	LNode *next;
};

/* 头插法建立链表 
①结点的次序和输入的次序是相反的*/
LNode *CreateListOfHead(){
	LNode *head=NULL,*p;
	char content;
	cin>>content;
	while(content != '$'){
		p = new LNode;
		p->data = content;
		p->next = head;
		head = p;
		cin>>content;
	}
	return head;
}


/* 尾插法建立链表 */
LNode *CreateListOfLast(){
	LNode *p,*head=NULL,*last=NULL;
	char con; cin>>con;
	while(con != '$'){
		p = new LNode;
		p->data = con;
		if(head==NULL) head = p;
		else last->next = p;
		last = p;
		cin >> con;
	}
	if(last != NULL) last->next = NULL;
	return head;
} 


void printList(LNode *a){
	LNode *test = a;
	while(test!=NULL){
		cout<<test->data<<" ";
		test = test->next; 
	}
} 

void TestTask(LNode *Head){
	LNode *q = Head;LNode *r,*p;
	while(q){
		r=q; p=q->next;
		cout<<"1"<<endl;
		while(p){
			if(p->data < r->data){
				r=p; p=p->next;
			}
			int x = r->data;
			r->data = q ->data;
			q->data = x;
			q=q->next;
			cout<<"2"<<endl;
		}
	}
	cout<<"ok"<<endl;
} 

int main(){
	//LNode *list = CreateListOfHead();
	//LNode *list2 = CreateListOfLast();
	//printList(list2);
//	if(NULL) cout<<1;
//	else cout<<0;
	LNode *list2 = CreateListOfLast();
	TestTask(list2);
	return 0;
}



















