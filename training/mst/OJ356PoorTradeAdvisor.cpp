#define _CRT_SECURE_NO_WARNINGS
#define MAX 510
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<limits.h>
using namespace std;
struct Edge 
{
	int from, to, len;
}Edges[1000000];
int p[MAX];
bool visited[MAX];
void init() 
{
	memset(p, -1, sizeof(p));
	memset(visited, 0, sizeof(visited));
}
int find(int x) 
{ 
	return p[x]<0 ? x : p[x] = find(p[x]); 
}
void Union(int x, int y) 
{
	int rt1 = find(x),rt2=find(y);
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
int CMP(const void*a, const void*b)
{
	Edge * A = (Edge *)a;
	Edge * B = (Edge *)b;
	return (*B).len - (*A).len;
}
void Kruskal(int leng,int max) 
{
	qsort(Edges,leng,sizeof(Edge),CMP);
	for (int i = 0;i < leng;i++) 
	{
		if (Edges[i].len != max)
			continue;
		if (find(Edges[i].from) == (find(Edges[i].to)))
			continue;
		Union(Edges[i].from, Edges[i].to);
		visited[Edges[i].from] = 1;
		visited[Edges[i].to] = 1;
	}
}
int main()
{
	int cities=0, roads=0;
	while (scanf("%d %d", &cities, &roads) && cities != 0 && roads != 0) 
	{
		int max = INT_MIN;
		init();
		for (int i = 0;i < roads;i++)
		{
			int from = 0, to = 0, len = 0;
			scanf("%d %d %d", &from, &to, &len);
			if (len > max)max = len;
			Edges[i].from=from;
			Edges[i].to = to;
			Edges[i].len = len;
		}
		Kruskal(roads,max);
		int maxCity = 10;
		for (int j = 0;j <= cities;j++) 
		{
			if (visited[j]) 
				maxCity = p[j] < maxCity ? p[j] : maxCity; 
		}
		printf("%d\n", -maxCity);
	}
}