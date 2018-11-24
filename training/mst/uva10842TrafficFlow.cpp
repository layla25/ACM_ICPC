#define _CRT_SECURE_NO_WARNINGS
#define INF 2147383647
#define MAX 106
#include<stdio.h>
#include<cstring>
using namespace std;
int adj[MAX][MAX];
int d[MAX];
bool visited[MAX];
void init() 
{
	for (int i = 0;i < MAX;i++) 
	{ 
		d[i] = -1;
		visited[i] = false;
		for (int j = 0;j < MAX;j++)
			adj[i][j] = -1;
	}
}
void Prim(int nodeNum) 
{
	d[0] = 0;
	visited[0] = true;
	for (int k = 0;k < nodeNum;k++)
	{
		if (!visited[k] && adj[0][k] > d[k])
			d[k] = adj[0][k];
	}
	int totalmin = INF;
	for (int i = 0;i < nodeNum;i++) 
	{
		int max = -1, maxIndex = -1, b = -1;
		for (int j = 0;j < nodeNum;j++)
			if (!visited[j] && d[j] > max) 
			{
				maxIndex = j;
				max = d[j];
			}
		if (maxIndex == -1)break;
		totalmin = totalmin < max ? totalmin : max;
		visited[maxIndex] = true;
		for (int k = 0;k < nodeNum;k++) 
		{
			if (!visited[k] && adj[maxIndex][k] > d[k])
				d[k] = adj[maxIndex][k];
		}
	}
	printf("%d\n", totalmin);
}
int main() 
{
	int N=0;
	scanf("%d", &N);
	for (int i = 0;i < N;i++)
	{
		int n = 0, m = 0;
		init();
		scanf("%d %d", &n, &m);
		while (m--) 
		{
			int u = 0, v = 0, c = 0;
			scanf("%d %d %d", &u, &v, &c);
			if (u == v)continue;
			if (c > adj[u][v]) 
			{
				adj[u][v] = c;
				adj[v][u] = c;
			}
		}
		printf("Case #%d: ",i+1);
		Prim(n);
	}
	return 0;
}
