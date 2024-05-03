#include<bits/stdc++.h>
using namespace std;
#define MAXN 500
/*3、编写一个函数：void replace(char rs[],char a[],char s1[],const char s2[])，
在字符串a中查找是否有s1子串，如果有，就将s1子串替换为s2串，
最后将结果串写入到形参rs串中，写一个主函数测试结果（文件名test3.cpp）*/
int len = 0;
void replace(char rs[],char a[],char s1[],char s2[]){
	for(int i=0;i<strlen(a);i++){
		int index=0,j;
		for(j=i;j<i+strlen(s1);j++){
			if(a[j]!=s1[index++]) break;
		}
		if(j==i+strlen(s1)){
			for(int k=0;k<strlen(s2);k++){
				rs[len++]=s2[k];
			}
			i=i+strlen(s1)-1;			
		}else{
			rs[len++]=a[i];
		}
	}
}

int main(){
	char rs[MAXN];char a[MAXN];char s1[MAXN];char s2[MAXN];
	cin>>a>>s1>>s2;
	replace(rs,a,s1,s2);
	for(int i=0;i<len;i++) cout<<rs[i];
	return 0;
}


