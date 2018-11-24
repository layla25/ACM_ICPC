#define _CRT_SECURE_NO_WARNINGS
#define MAX 1010
#include<stdio.h>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
struct Edge 
{
	int from, to, len;
}Edges[25005];
int p[MAX];
vector<int>ans;
int CMP(const void* A, const void* B) 
{
	Edge*a = (Edge*)A;
	Edge*b = (Edge*)B;
	return a->len - b->len;
}
int find(int x) 
{
	return p[x] < 0 ? x : p[x]=find(p[x]);
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
	memset(p,-1,sizeof(p));
	ans.clear();
}
void Kruskal(int len,int nodes) 
{
	qsort(Edges, len, sizeof(Edge), CMP);
	int i = 0,j=0,cost=0;
	bool exceed = false;
	for (i = 0,j=0;i < len&&j<nodes-1;i++,j++) 
	{
		while (find(Edges[i].from) == find(Edges[i].to)) 
		{
			ans.push_back(Edges[i].len);
			i++;
			if (i >= len) 
			{
				exceed = true;
				break;
			}
		}
		if (exceed)break;
		Union(Edges[i].from,Edges[i].to);
		cost += Edges[i].len;
	}
	if (j == nodes - 1) 
	{
		for (int m = i; m < len;m++)
		{
			ans.push_back(Edges[m].len);
		}
		printf("Min cost: %d\n", cost);
		for (int k =0;k < ans.size();k++) 
		{
			printf("%d", ans[k]);
			if (k != ans.size()-1)
				printf(" ");
		}
		printf("\n");
	}
	else printf("\\(^o^)/ pray to god\n");
}
int main() 
{
	int n = 0, m = 0;
	while(scanf("%d %d",&n,&m)&&!(n==0&&m==0))
	{
		if (m == 0) 
		{
			printf("\\(^o^)/ pray to god\n");
			continue;
		}
		init();
		for (int i = 0;i < m;i++)
		{
			int from = 0, to = 0, len = 0;
			scanf("%d %d %d",&from,&to,&len);
			Edges[i].from = from;
			Edges[i].to = to;
			Edges[i].len = len;
		}
		Kruskal(m,n);
	}
}