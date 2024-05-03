#include<bits/stdc++.h>
using namespace std;
typedef int ElemType;

void Present(ElemType A[],int n){
	for(int i=1;i<=n;i++){
		cout<<A[i]<<"->";
	}
}

void InsertSort(ElemType A[],int n){
	int i,j;
	for(i=2;i<=n;i++){
		if(A[i]<A[i-1]){
			A[0]=A[i];
			for(j=i-1;A[j]>A[0];--j){
				A[j+1]=A[j];
			}
			A[j+1]=A[0];
		}
	}
}

int main(){
	
	ElemType s[] = {0,49,38,65,97,76,13,27,49};
	InsertSort(s,8);
	Present(s,8);
}













