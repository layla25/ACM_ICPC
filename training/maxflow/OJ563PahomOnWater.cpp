#define _CRT_SECURE_NO_WARNINGS
#define MAX 310*2
#include<stdio.h>
#include<stdlib.h>
#include<cstring>
#include<algorithm>
using namespace std;
int location[MAX][3];
float freq[MAX];
int adj[MAX][MAX];
int q[MAX], *qf, *qb;
int p[MAX];
int Edmonds(int s,int t,int size) 
{
	int f = 0;
	memset(q, 0, sizeof(q));
	while (1) 
	{
		memset(p, -1, sizeof(p));
		qf = qb = q;
		p[*qb++ = s] = s;
		while (qf < qb&&p[t] == -1)
		{
			for (int i = *qf++, j = 0;j < size;++j)
			{
				if (p[j] == -1 && adj[i][j])
					p[*qb++ = j] = i;
			}
		}
		if (p[t] == -1)break;
		int df = 1e9;
		for (int i = p[t], j = t;i != j;i = p[j = i])
			df = min(df, adj[i][j]);
		for (int i = p[t], j = t;i != j;i = p[j = i])
			adj[i][j] -= df, adj[j][i] += df;
		f += df;
	}
	return f;

}
int main() 
{
	int K = 0;
	scanf("%d", &K);
	while (K--) 
	{
		int N = 0,s=0,t=0;
		
		memset(adj, 0, sizeof(adj));
		scanf("%d", &N);
		for (int i = 0;i < N;i++) 
		{
			float frequency = 0;
			int x = 0, y = 0, r = 0;
			adj[2 * i][2 * i + 1] = 1;
			scanf("%f %d %d %d", &frequency, &x, &y, &r);
			location[i][0] = x, location[i][1] = y, location[i][2] = r;
			freq[i] = frequency;
			if (fabs(frequency - 400.0) <= 1e-5) s = i;
			else if(fabs(frequency  - 789.0) <= 1e-5) t = i;
			for (int j = i - 1;j >= 0;j--) 
			{
				if ((location[j][0] - x)*(location[j][0] - x) + (location[j][1] - y)*(location[j][1] - y) <= (r + location[j][2])*(r + location[j][2])) 
				{
					if (frequency < freq[j])
						adj[2*i+1][2*j] = 1;
					else if (frequency>freq[j])
						adj[2*j+1][2*i] = 1;
				}
			}
		}
		if (Edmonds(2 * s + 1, 2 * t, 2 * N) >= 2)
			printf("Game is VALID\n");
		else 
			printf("Game is NOT VALID\n");
		}
	return 0;
}