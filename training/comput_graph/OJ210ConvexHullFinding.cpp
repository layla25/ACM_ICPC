#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
using namespace std;
struct Point { int x;int y; }Points[512];
Point L[280], U[280];
double cross(Point& o, Point& a, Point& b)
{
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool compare(Point& a, Point& b)
{
	return a.y < b.y || (a.y == b.y&&a.x < b.x);
}
void Andrew(int N)
{
	sort(Points, Points + N, compare);
	int l = 0, u = 0;
	for (int i = 0;i < N;++i)
	{
		while (l >= 2 && (cross(L[l - 2], L[l - 1], Points[i]) <= 0))l--;
		while (u >= 2 && (cross(U[u - 2], U[u - 1], Points[i]) >= 0))u--;
		L[l++] = Points[i];
		U[u++] = Points[i];
	}
	printf("%d\n",l+u-1);
	for (int j = 0;j < l;j++) 
	{
		printf("%d %d\n", L[j].x, L[j].y);
	}
	for (int k = u-2;k >= 0;k--)
	{
		printf("%d %d\n", U[k].x, U[k].y);
	}
}
int main()
{
	int cases = 0,rubbish = 0;
	scanf("%d", &cases);
	printf("%d\n",cases);
	while (cases--)
	{
		int N = 0;
		scanf("%d", &N);
		for (int i = 0;i < N;i++)
		{
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			Points[i].x = x;
			Points[i].y = y;
		}
		Andrew(N);
		if (cases) {
			scanf("%d", &rubbish);
			printf("-1\n");
		}
	}
	return 0;
}