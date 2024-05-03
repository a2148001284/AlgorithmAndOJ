#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
using namespace std;
const int N = 100;
int G[N][N];
int path[N], visited[N], n, cycle;
int DFS(int u, int start)
{
	int i;
	visited[u] = -1;
	path[u] = start;
	for (i = 0; i < n;i++)
	{
		if (G[u][i]&&i!=start)
		{
			if (visited[i]<0)
			{
				cycle = u;
				return 0;
			}
			if (!DFS(i,u))
			{
				return 0;
			}
		}
	}
	visited[u] = 1;
	return 1;
}
 
void DisPath(int u)
{
	if (u<0)
	{
		return;
	}
	DisPath(path[u]);
	cout << " " << u;
 
}
 
int main()
{
	int i, j;
	cout << "请输入图中的顶点个数：" << endl;
	cin >> n;
	memset(G, 0, sizeof(G));
	cout << "请输入一个" << n << "*" << n << "矩阵（1表示存在弧，0表示不存在弧）：" << endl;
	for (i = 0; i < n;i++)
	{
		for (j = 0; j < n;j++)
		{
			cin >> G[i][j];
		}
	}
	cycle = -1;
	for (i = 0; i < n;i++){
		if (!visited[i]&&!DFS(i,-1))
		{
			break;
		}
	}
	if (cycle<0)
	{
		cout << "不存在环!" << endl;
	} 
	else
	{
		cout << "存在环!" << endl;
		DisPath(cycle);
		cout << endl;
	}
 
	system("pause");
	return 0;
}
