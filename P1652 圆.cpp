#include<bits/stdc++.h>
using namespace std;
//算法：遍历所有的圆 如果点1在其中而点2不在 就会分割一个（异或） 
double GetDis(int x1,int y1,int x2,int y2){
	return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main(){
	int n;scanf("%d",&n);
	int x[n+1],y[n+1],r[n+1];
	int x1,y1,x2,y2;int ans=0;
	for(int i=1;i<=n;i++) scanf("%d",&x[i]);
	for(int i=1;i<=n;i++) scanf("%d",&y[i]);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	for(int i=1;i<=n;i++)
		if((GetDis(x1,y1,x[i],y[i])<r[i])^(GetDis(x2,y2,x[i],y[i])<r[i])) ans++; //^为异或符号 
	printf("%d",ans);
	return 0;
} 

 
