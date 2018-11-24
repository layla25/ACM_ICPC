#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
struct Point { int x;int y; }Points[110];
Point L[110], U[110];
double cross(Point& o,Point& a,Point& b) 
{
	return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
bool compare(Point& a, Point& b) 
{
	return a.x < b.x || (a.x == b.x&&a.y < b.y);
}
float Andrew(int N) 
{
	sort(Points, Points + N, compare);
	int l = 0, u = 0;
	float area = 0;
	for (int i = 0;i < N;++i) 
	{
		while (l >= 2 && (cross(L[l - 2], L[l - 1], Points[i])<=0))l--;
		while (u >= 2 && (cross(U[u - 2], U[u - 1], Points[i])>=0))u--;
		L[l++] = Points[i];
		U[u++] = Points[i];
	}
	for (int i = 0, j = 1;j < l;i = j++)
	{
		area += L[i].x*L[j].y - L[j].x*L[i].y;
	}
	for (int i = 0, j = 1;j < u;i = j++)
	{
		area -= U[i].x*U[j].y - U[j].x*U[i].y;
	}
	return area;
}
int main() 
{
	int N = 0,cases=1;
	while (scanf("%d", &N)&&N) 
	{
		float area = 0;
		for (int i = 0;i < N;i++) 
		{
			int x = 0, y = 0;
			scanf("%d %d", &x, &y);
			Points[i].x = x;
			Points[i].y = y;
		}
		for (int i=N-1,j = 0;j < N;i=j++) 
		{
			area += Points[i].x*Points[j].y-Points[j].x*Points[i].y;
		}
		printf("Tile #%d\n", cases++);
		printf("Wasted Space = %.2lf %%\n\n", 100-100*fabs(area) / Andrew(N));
	}
}