#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits>
#include<math.h>
using namespace std;
bool isZero(double x)
{
	return fabs(x) < 1e-15;
}
int main() 
{
	double D = 0.0;
	while (scanf("%lf", &D) && !isZero(D)) 
	{
		double px = 0.0, py = 0.0, vx = 0.0, vy = 0.0;
		scanf("%lf %lf %lf %lf",&px,&py,&vx,&vy);
		double cross = px*vy - py*vx;
		if (isZero(px) && isZero(py)) 
		{
			printf("possible\n");
			continue;
		}
		if (isZero(cross))
		{
			double dist = sqrt(px*px + py*py);
			double dot = px*vx + py*vy;
			double toTravel = dist;
			if (dot > 0)
				toTravel = 2.0 - dist;
			if(isZero(dot))printf("impossible\n");
			else if(toTravel<D||isZero(toTravel-D))
				printf("possible\n");
			else printf("impossible\n");
		}
		else printf("impossible\n");
	}
	return 0;
}