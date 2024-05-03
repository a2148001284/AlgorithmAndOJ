#include<bits/stdc++.h>
using namespace std;
//void test(){
//	//cin用空格/空白来结束 最前面的空格不会被识别 
//	char a[10];string b;  //  abc 111
//	scanf("%s",a);
//	cin>>b;  
//	cout<<a<<endl;  //abc
//	cout<<b<<endl;  //111
//}
int main(){
	//可行 但是会TLE 建议使用string类的方法 或者（优化） 本次不行就看下次单词 而不是挨个查 
	char a[1000005];char b[11];int flag=1;int ans=0;int first=0;
	//test();
	//为了精确匹配 必须要在两者的头尾都加空格才可以
	//cin.getline(b,11);cin.getline(a,1000005); 可行 但是要加空格
	b[0]=' ';a[0]=' ';
	gets(b+1);gets(a+1);//cin.getline(b+1,11);cin.getline(a+1,1000005);
	strcat(a," ");strcat(b," "); //b[strlen(b)]=' ';a[strlen(a)]=' ';
	//cout<<strlen(a)<<" "<<strlen(b)<<endl; 
	for(int i=0;i<strlen(a);i++) a[i]=tolower(a[i]);
	for(int j=0;j<strlen(b);j++) b[j]=tolower(b[j]);
	//cout<<a<<endl<<b<<endl;
	//cout<<strlen(a)<<" "<<strlen(b)<<endl; 输入没有问题 
	for(int i=0;i<strlen(a);i++){
		if(a[i]==' ' && a[i+1]!=' '){
			int index=0,j;
			for(j=i;j<i+strlen(b);j++) if(a[j]!=b[index++]) break;
			if(j==i+strlen(b)){
				ans++;
				if(flag){
					first=i;flag=0;
				}
			}	
		}	
	}
	if(ans>0) printf("%d %d",ans,first);
	else printf("-1");
	return 0;
}






