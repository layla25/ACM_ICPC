#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
using namespace std;
int bag[31] = { 0 };
int main()
{
	int T = 0;
	scanf("%d", &T);
	while (T--) 
	{
		int N=0,G=0;
		memset(bag, 0, sizeof(bag));
		scanf("%d", &N);
		while (N--) 
		{
			int P = 0, W = 0;
			scanf("%d %d" ,&P, &W);
			for (int i = 30 ;i >= W;i--)
				bag[i] = bag[i-W]+P>bag[i]? bag[i - W] + P:bag[i];
		}
		scanf("%d",&G);
		int maxValue = 0;
		while (G--) 
		{
			int MW = 0;
			scanf("%d", &MW);
			maxValue += bag[MW];
		}
		printf("%d\n",maxValue);
	}
	return 0;
}