#include<bits/stdc++.h>
#define MAXN 1005
using namespace std;
int n,a[MAXN][MAXN];int ans=0;

void Get(int x,int y){
	int tmp=0;
	for(int i=1;i<=n;i++){
		tmp+=a[x][i];tmp+=a[i][y];
	}
	ans=max(ans,tmp);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	for(int j=1;j<=n;j++) scanf("%d",&a[i][j]);
	int flag=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			if(a[i][j]==0) flag=1,Get(i,j);
		}
	if(flag==0) printf("Bad Game!");
	else printf("%d",ans);
	return 0;
}







