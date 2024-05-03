#include<bits/stdc++.h>
using namespace std;
int lists[50]={0,990,1010,1970,2030,2940,3060,3930,4060,4970,5030,5990,6010,7000};
int ans[50];
int A,B,N;
/*
1.一个数组储存所有旅馆，初始化时先存下前面14个旅馆。
2.输入新添加旅馆后，将所有旅馆排序，方便日后比较。
3.根据斐波那契数列，如果可以从A点走到B点，那么A点的总方案数应该加上B点的方案数。
4.循环进行3操作即可（但B点只需要是A点前面的点）。
*/ 
int main(){
	scanf("%d%d%d",&A,&B,&N);
	if(N>=1) for(int i=14;i<=13+N;i++) scanf("%d",&lists[i]);
	sort(lists,lists+14+N);//旅馆距离从小到达递增
	ans[0]=1;
	for(int i=1;i<=13+N;i++) //斐波那契思想递推 
		for(int j=0;j<i;j++){
			if(lists[j]+A<=lists[i] && lists[j]+B>=lists[i]){
				ans[i]+=ans[j];
			}
		}
	cout<<ans[13+N]<<endl;
	return 0;
}







