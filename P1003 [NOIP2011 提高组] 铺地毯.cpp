#include<bits/stdc++.h>
using namespace std;
#define MAXV 100005
int n;int x,y;int mark=-1;
struct square{
	int x1;int x2;int y1;int y2;
}node[10005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&node[i].x1);
		scanf("%d",&node[i].y1);
		int x2,y2;scanf("%d",&x2);scanf("%d",&y2);
		node[i].x2=node[i].x1+x2;
		node[i].y2=node[i].y1+y2;
	}
	scanf("%d",&x);scanf("%d",&y);
	for(int i=1;i<=n;i++){
		if(node[i].x1<=x && x<=node[i].x2 && node[i].y1<=y && y<=node[i].y2){
			mark=i;
		}
	}
	printf("%d",mark);
	return 0;
}












