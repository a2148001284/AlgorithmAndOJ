#include<bits/stdc++.h>
#define MAXN 1000
using namespace std;
char a[MAXN],b[MAXN];
int lena,lenb;
int main(){
	cin>>a+1;cin>>b+1;
	lena=strlen(a+1);lenb=strlen(b+1);int next[MAXN];
	//Çónext 
	next[1]=0;int i=1,j=0;
	while(i<=lenb){
		if(j==0 || b[i]==b[j]){
			++i,++j;next[i]=j;
		}else j=next[j];
	}
	//¿ªÊ¼Æ¥Åä
	i=1,j=1;
	while(i<=lena && j<=lenb){
		if(j==0 || a[i]==b[j]) ++i,++j;
		else j=next[j];
		if(j>=lenb+1) printf("%d\n",i-lenb),j=next[j];
	}
	return 0;
}

