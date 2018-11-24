#define _CRT_SECURE_NO_WARNINGS
#define MAX 1010
#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
struct Edge
{
	int from, to, len;
}Edges[10010];
int p[MAX];
int CMP(const void* A, const void* B)
{
	Edge*a = (Edge*)A;
	Edge*b = (Edge*)B;
	return a->len - b->len;
}
int find(int x)
{
	return p[x] < 0 ? x : p[x] = find(p[x]);
}
void Union(int x, int y)
{
	int rt1 = find(x), rt2 = find(y);
	if (p[rt1] < p[rt2])
	{
		p[rt1] += p[rt2];
		p[rt2] = rt1;
	}
	else
	{
		p[rt2] += p[rt1];
		p[rt1] = rt2;
	}
}
void init()
{
	memset(p, -1, sizeof(p));
}
int Kruskal(int len, int nodes,int begin)
{
	int i = 0, j = 0,max=-1,min=10010;
	init();
	for (i = begin, j = 0;i < len&&j<nodes - 1;i++, j++)
	{
		while (find(Edges[i].from) == find(Edges[i].to)&&i<len)
			i++;
		if (i == len)break;
		Union(Edges[i].from, Edges[i].to);
		max = max > Edges[i].len ? max : Edges[i].len;
		min = min < Edges[i].len ? min : Edges[i].len;
	}
	if (j == nodes - 1)
		return max-min;
	else return -1;
}
int main()
{
	int n = 0, m = 0;
	while (scanf("%d %d", &n, &m) && (n != 0 || m != 0))
	{
		init();
		for (int i = 0;i < m;i++)
		{
			int from = 0, to = 0, len = 0;
			scanf("%d %d %d", &from, &to, &len);
			Edges[i].from = from;
			Edges[i].to = to;
			Edges[i].len = len;
		}
		qsort(Edges, m, sizeof(Edge), CMP);
		int minSlim = 1e9;
		for (int j = 0;j <= m - n + 1;j++)
		{
			int a = Kruskal(m, n, j);
			if (a!=-1)
				minSlim = minSlim < a ? minSlim : a;
		}
		if (minSlim == 1e9)printf("-1\n");
		else printf("%d\n", minSlim);
	}
}