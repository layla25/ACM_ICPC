#define _CRT_SECURE_NO_WARNINGS
#define MAX 25+1005+2
#include<stdio.h>
#include<cstring>
#include<queue>
using namespace std;
int adj[MAX][MAX];
int parent[MAX];
bool visited[MAX];
void Edmonds(int s,int t,int np,int nk) 
{
	int maxFlow = 0;
	while (1) 
	{
		memset(parent, -1, sizeof(parent));
		queue<int>nodes;
		parent[s] = s;
		nodes.push(s);
		while (!nodes.empty() && parent[t] == -1) 
		{
			int current = nodes.front();
			nodes.pop();
			for (int i = 0;i <= t;i++) 
			{
				if (parent[i] == -1 && adj[current][i])
				{
					parent[i] = current;
					nodes.push(i);
				}
			}
		}
		if (parent[t]==-1)break;
		int df = 1e9;
		for (int i = parent[t], j = t;j != i;j = i, i = parent[j])
			df = min(df, adj[i][j]);
		for (int i = parent[t], j = t;j != i;j = i, i = parent[j])
			adj[i][j] -= df, adj[j][i] += df;
		maxFlow += df;
	}
	bool flag = true;
	for (int k = np + 1;k <= np + nk;k++)
		if (adj[k][t]) 
		{
			flag = false;
			break;
		}
	if (flag)
		printf("1\n");
	else printf("0\n");
}
int main() 
{
	int nk = 0, np = 0;
	while (scanf("%d %d", &nk, &np) && nk != 0) 
	{
		memset(adj, 0, sizeof(adj));
		int ind = np,tink=1+nk+np;
		for (int i = 0;i < nk;++i)
		{
			scanf("%d", &adj[++ind][tink]);
		}
		for (int j = 1;j <= np;j++) 
		{
			int n = 0,to=0;
			adj[0][j] = 1;
			scanf("%d", &n);
			while (n--) {
				scanf("%d", &to);
				adj[j][to+np] = 1;
			}
		}
		Edmonds(0,tink,np,nk);
	}
}