#include<cstdio>
#define MAX_N 20
#define ll long long
using namespace std;
int n;
ll f[MAX_N][MAX_N]; //1:��ʾ��ջ�����������   2:��ʾ��ջ����������� 
//������� Ŀǰ��û����� 
int main()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
	{
		f[0][i]=1;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==j)f[i][j]=f[i-1][j];  //
			else f[i][j]=f[i][j-1]+f[i-1][j];
		}
	}
	printf("%lld",f[n][n]);
	return 0;
}

