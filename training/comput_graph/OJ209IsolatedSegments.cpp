#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<cstring>
#include<limits>
using namespace std;
struct Point
{
	float x;float y;
}Points[210];
bool notIsolated[105];
bool isZero(float x) 
{
	return fabs(x) <= numeric_limits<float>::epsilon();
}
float dot(Point& o, Point& a, Point& b)
{
	return (a.x - o.x) * (b.x - o.x) + (a.y - o.y) * (b.y - o.y);
}
float cross(Point& o, Point& a, Point& b)
{
	return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
}
bool intersect(Point &p, Point &p1, Point &p2)
{
	float Dot = dot(p, p1, p2);
	return isZero(cross(p, p1, p2)) && (Dot< 0||isZero(Dot));
}
bool intersect(Point& a1, Point& a2, Point& b1, Point& b2)
{
	float c1 = cross(a1, a2, b1);
	float c2 = cross(a1, a2, b2);
	float c3 = cross(b1, b2, a1);
	float c4 = cross(b1, b2, a2);
	if (c1 * c2 < 0 && c3 * c4 < 0) return true;
	if (isZero(c1)&& intersect(b1 ,a1, a2)) return true;
	if (isZero(c2) && intersect(b2, a1, a2)) return true;
	if (isZero(c3) && intersect(a1, b1, b2)) return true;
	if (isZero(c4) && intersect(a2, b2, b1)) return true;
	return false;
}
int main()
{
	int testcases = 0;
	scanf("%d", &testcases);
	while (testcases--)
	{
		int N = 0,count=0;
		memset(notIsolated,0, sizeof(notIsolated));
		scanf("%d", &N);
		for (int i = 0;i < N;i++)
		{
			int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
			scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
			Points[2 * i].x = x1, Points[2 * i].y = y1;
			Points[2 * i+1].x = x2, Points[2 * i+1].y = y2;
			for (int j = i-1;j >= 0;j--) 
			{
				if (intersect(Points[2 * i], Points[2 * i + 1], Points[2 * j], Points[2 * j + 1]))
				{
					notIsolated[i] = true;
					notIsolated[j] = true;
				}
			}
		}
		for (int k = 0;k < N;k++)
		{
			if (!notIsolated[k])
				count++;
		}
		printf("%d\n", count);
	}
}
