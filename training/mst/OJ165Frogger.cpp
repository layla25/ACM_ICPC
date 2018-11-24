#define _CRT_SECURE_NO_WARNINGS
#define MAX 210
#include<stdio.h>
#include<cstring>
#include<vector>
#include<array>
#include<math.h>
#include<algorithm>
using namespace std;
struct Edge
{
	int from, to;
	double len;
}Edges[20010];
int p[MAX];
vector<array<int, 2>>nodes;
int CMP(const void* A, const void* B)
{
	Edge*a = (Edge*)A;
	Edge*b = (Edge*)B;
	if (a->len - b->len > 0)return 1;
	else if (a->len == b->len)return 0;
	else return -1;
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
	nodes.clear();
}
void Kruskal(int len, int nodes)
{
	qsort(Edges, len, sizeof(Edge), CMP);
	int i = 0, j = 0;
	double max = -1;
	for (i = 0, j = 0;i < len&&j<nodes - 1;i++, j++)
	{
		while (find(Edges[i].from) == find(Edges[i].to) && i<len)
			i++;
		if (i == len)break;
		Union(Edges[i].from, Edges[i].to);
		max = max > Edges[i].len ? max : Edges[i].len;
		if (find(0) == find(1))
			break;
	}
	if (find(0) == find(1))
		printf("%.3lf\n\n", max);
}
int main()
{
	int n = 0,cases=1;
	while (scanf("%d", &n) && n != 0)
	{
		init();
		for (int i = 0;i < n;i++)
		{
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			nodes.push_back({ x,y });
		}
		int ind = 0;
		for (int j = 0;j < nodes.size();j++)
			for (int k = j;k < nodes.size();k++) 
			{
				if (j == k)continue;
				Edges[ind].from = j;
				Edges[ind].to = k;
				Edges[ind].len = sqrt((nodes[j].at(0)-nodes[k].at(0))*(nodes[j].at(0) - nodes[k].at(0))+ (nodes[j].at(1) - nodes[k].at(1))*(nodes[j].at(1) - nodes[k].at(1)));
				ind++;
			}
		printf("Scenario #%d\nFrog Distance = ", cases++);
		Kruskal(n*(n-1)/2,n);
	}
}