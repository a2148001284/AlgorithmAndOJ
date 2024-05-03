#include<bits/stdc++.h>
using namespace std;
#define MAXN 100
int n;
//卡点1:数组一开始用的是bool 而赋值一旦赋的不是1 就会默认为1 就会导致出错 
//卡点2:MAXN的数值一开始给小了 应该大点才行
//卡点3:用i作为dfs量 每次其中循环所有列这种思想第一次接触 
int lie_flag[MAXN];
int hang_flag[MAXN];
int zhu_xie_flag[MAXN];//i-j+n唯一对应 
int fu_xie_flag[MAXN];//i+j唯一对应 
int counts=0;
void print(){
	counts++;
	if(counts<=3){
		for(int i=1;i<=n;i++) 
			printf("%d ",hang_flag[i]);
		printf("\n");
	}
}
void dfs(int i){ //设i为行 其中循环j表示每一列 
	if(i>n){
		print();
		return;
	}
	for(int j=1;j<=n;j++){  //j表示每一列 
		if(lie_flag[j]==0 && hang_flag[i]==0 && zhu_xie_flag[i-j+n]==0 && fu_xie_flag[i+j]==0){
			lie_flag[j]=1;hang_flag[i]=j;zhu_xie_flag[i-j+n]=1;fu_xie_flag[i+j]=1;dfs(i+1);
			lie_flag[j]=0;hang_flag[i]=0;zhu_xie_flag[i-j+n]=0;fu_xie_flag[i+j]=0;//回溯 
		}
	}
}

int main(){
	scanf("%d",&n);
	fill(lie_flag,lie_flag+MAXN,0);
	fill(hang_flag,hang_flag+MAXN,0);
	fill(zhu_xie_flag,zhu_xie_flag+MAXN,0);
	fill(fu_xie_flag,fu_xie_flag+MAXN,0);
	dfs(1);
	printf("%d",counts); 
	return 0;
}



