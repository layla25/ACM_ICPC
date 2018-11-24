#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<limits>
using namespace std;
struct Point { float x;float y; }Points[6];
bool isZero(float x) 
{
	return fabs(x) < numeric_limits<float>::epsilon();
}
float dot(Point&o, Point&a, Point&b) 
{
	return (a.x - o.x)*(b.x - o.x) + (a.y - o.y)*(b.y - o.y);
}
float cross(Point&o, Point&a, Point&b)
{
	return (a.x - o.x)*(b.y - o.y) - (a.y - o.y)*(b.x - o.x);
}
bool intersect(Point& a1, Point& a2, Point& b1, Point& b2) 
{
	float c1 = cross(a1, a2, b1);
	float c2 = cross(a1, a2, b2);
	float c3 = cross(b1, b2, a1);
	float c4 = cross(b1, b2, a2);
	if (c1*c2 < 0 && c3*c4 < 0)return true;
	float d1 = dot(b1, a1, a2);
	if (isZero(c1) && (d1 < 0 || isZero(d1)))return true;
	float d2 = dot(b2, a1, a2);
	if (isZero(c2) && (d2 < 0 || isZero(d2)))return true;
	float d3 = dot(a1, b1, b2);
	if (isZero(c3) && (d3 < 0 || isZero(d3)))return true;
	float d4 = dot(a2, b1, b2);
	if (isZero(c4) && (d4 < 0 || isZero(d4)))return true;
	return false;
}
int main() 
{
	int N = 0;
	scanf("%d", &N);
	while (N--) 
	{
		bool ans=false;
		int l = 0, t = 0, r = 0, b = 0;
		int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
		scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &l, &t, &r,&b);
		Points[0].x = x1, Points[0].y = y1;
		Points[1].x = x2, Points[1].y = y2;
		Points[2].x = l, Points[2].y = t;
		Points[3].x = r, Points[3].y = t;
		Points[4].x = r, Points[4].y = b;
		Points[5].x = l, Points[5].y = b;
		for (int i = 2;i <= 5;++i)
		{
			for (int j = 2;j <= 5;++j)
			{
				if (i == j)continue;
				if (ans = intersect(Points[0], Points[1], Points[i], Points[j]))
					break;
			}
			if (ans)break;
		}
		if (ans)printf("T\n");
		else printf("F\n");
	}

}