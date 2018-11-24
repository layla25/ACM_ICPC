#define _CRT_SECURE_NO_WARNINGS
#define INF 0x7fffffff
#include<cstring>
#include<queue>
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Edge 
{
	int v,flow,nxt;
}Edges[120020];
int totalEdge;
int head[5005];
bool visited[5005];
int d[5005];
void init() 
{
	totalEdge = 0;
	memset(head, -1, sizeof(head));
	memset(visited, false, sizeof(visited));
}
void addEdge(int u, int v, int flow) 
{
	Edges[totalEdge].v = v;
	Edges[totalEdge].flow = flow;
	Edges[totalEdge].nxt = head[u];
	head[u] = totalEdge++;
}
bool bfs(int s, int t) 
{
	queue<int>Q;
	memset(d, -1, sizeof(d));
	Q.push(s);
	d[s] = 0;
	while (!Q.empty()) 
	{
		int u = Q.front();
		Q.pop();
		for (int i = head[u];i != -1;i = Edges[i].nxt) 
		{
			int v = Edges[i].v;
			if (d[v] == -1 && Edges[i].flow) 
			{
				d[v] = d[u] + 1;
				Q.push(v);
				if (v == t)return 1;
			}
		}
	}
	return 0;
}
int dinic(int u,int t,int sum) 
{
	if (u == t)return sum;
	int temp = sum;
	for (int i = head[u];i != -1 && sum;i = Edges[i].nxt) 
	{
		int v = Edges[i].v;
		if (d[v] == d[u] + 1 && Edges[i].flow) 
		{
			int df = dinic(v, t, min(sum, Edges[i].flow));
			Edges[i].flow -= df;
			Edges[i ^ 1].flow += df;
			sum -= df;
		}
	}
	return temp - sum;
}
long long maxFlow(int s, int t) 
{
	long long ans = 0;
	while (bfs(s, t))
	{
		ans += dinic(s, t, INF);
	}
	return ans;
}
int dfs(int u,int s) 
{
	if (u == s)return 1;
	visited[u] = 1;
	int num = 1;
	for (int i = head[u] ;i!= -1;i = Edges[i].nxt) 
	{
		if (Edges[i].flow > 0 && !visited[Edges[i].v])
			num+= dfs(Edges[i].v, s);
	}
	return num;
}
int main() 
{
	int n = 0, m = 0;
	while (scanf("%d %d", &n, &m) != EOF)
	{
		init();
		long long positiveSum = 0;
		int s = 0, t = 1;
		for (int i = 0;i < n;i++)
		{
			int value = 0;
			scanf("%d", &value);
			if (value > 0)
				addEdge(s, i + 2, value), addEdge(i + 2, s, 0),positiveSum+=value;
			else if (value < 0)
				addEdge(i + 2, t, -value), addEdge(t, i + 2, 0);
		}
		while (m--) 
		{
			int j = 0,k = 0;
			scanf("%d %d", &j, &k);
			addEdge(j + 1, k + 1, INF), addEdge(k + 1, j + 1, 0);
		}
		long long maxProfit = positiveSum - maxFlow(s, t);
		printf("%d %lld\n", dfs(s,t)-1,maxProfit);
	}
}