#define _CRT_SECURE_NO_WARNINGS
#define MAX 505
#define INF 1e9;
#include<stdio.h>
#include<vector>
#include<math.h>
#include<cstring>
#include<array>
using namespace std;
vector<array<int,4>>nodes;
int adj[MAX][MAX];
int d[MAX];
bool visited[MAX];
void Prim(int nodesNum) 
{
	d[1] = 0;
	visited[0] = true;
	int len = 0;
	int min = INF;
	for (int m = 1;m <= nodesNum;m++) 
	{
		if (adj[0][m] < min)
			min = adj[0][m];
	}
	len += min;
	for (int i = 1;i <= nodesNum;i++) 
	{
		min = INF;
		int minIndex = -1;
		for (int j = 1;j <= nodesNum;j++) 
		{
			if (!visited[j]&&d[j] < min)
			{
				min = d[j];
				minIndex = j;
			}
		}
		if (minIndex == -1)break;
		visited[minIndex] = true;
		len += min;
		for (int k = 1;k <= nodesNum;k++) 
		{
			if (!visited[k] && adj[minIndex][k] < d[k])
				d[k] = adj[minIndex][k];
		}
	}
	printf("%d\n", len);
}
int main() 
{
	int T = 0;
	scanf("%d", &T);
	while (T--) 
	{
		int N = 0;
		scanf("%d", &N);
		nodes.clear();
		for (int i = 0;i < N+1;i++)
			d[i] = INF;
		memset(visited, 0, sizeof(visited));
		nodes.push_back({ 0,0,0,0 });
		for (int i = 0;i < N;i++)
		{
			int pw = 0;
			scanf("%d", &pw);
			int a = pw / 1000,b=pw/100-a*10,c=pw/10-b*10-a*100,d=pw-c*10-b*100-a*1000;
			nodes.push_back({a,b,c,d});
		}
		for (int j = 0;j <= N;j++)
			for (int k = j;k <= N;k++)
			{
				int len = 0;
				if (j == k)continue;
				for (int t = 0;t < 4;t++) 
				{
					int counterckwise = abs(nodes[j].at(t) - nodes[k].at(t));
					int clockwise = 10 - counterckwise;
					len += counterckwise < clockwise ? counterckwise : clockwise;
				}
				adj[j][k] = len;
				adj[k][j] = len;
			}
		Prim(N);
	}
}