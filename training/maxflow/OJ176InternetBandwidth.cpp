#define _CRT_SECURE_NO_WARNINGS	
#define MAX 110
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
int adj[MAX][MAX];
int queue[MAX], *front, *back;
int parent[MAX];
int Edmonds(int s,int t)
{
	int maxFlow = 0;
	while (1) 
	{
		memset(parent, -1,sizeof(parent));
		front = back = queue;
		parent[*back++ = s] = s;
		while (front < back&&parent[t] == -1)
			for (int i = *front++, j = 0;j < MAX;++j)
				if (parent[j] == -1 && adj[i][j])
					parent[*back++ = j] = i;
		if (parent[t] == -1)break;
		int df = 1e9;
		for (int i = parent[t], j = t;i != j;i = parent[j = i])
			df = min(df, adj[i][j]);
		for (int i = parent[t], j = t;i != j;i = parent[j = i])
			adj[i][j] -= df, adj[j][i] += df;
		maxFlow += df;
	}
	return maxFlow;
}
int main() 
{
	int nodes = 0, ind = 1;
	while (scanf("%d", &nodes)&&nodes!=0) 
	{
		int s = 0,t = 0,c = 0;
		memset(adj,0,sizeof(adj));
		memset(queue, 0, sizeof(queue));
		scanf("%d %d %d",&s,&t,&c);
		while (c--) 
		{
			int from = 0, to = 0, cost = 0;
			scanf("%d %d %d",&from,&to,&cost);
			adj[from - 1][to - 1] += cost;
			adj[to - 1][from - 1] += cost;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n",ind++,Edmonds(s-1,t-1));
	}
}
