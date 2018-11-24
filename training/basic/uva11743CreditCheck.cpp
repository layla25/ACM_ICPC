#include<stdio.h>
using namespace std;
int main() 
{
	int cases = 0;
	scanf("%d", &cases);
	while (cases--) 
	{
		int time = 8, sum1 = 0, sum2 = 0;;
		while (time--)
		{
			int a = getchar();
			if (a == ' '||a=='\n') 
			{ 
				time++;
				continue; 
			}
			else a -= '0';
			int b = getchar()-'0';
			sum1 += (a * 2) / 10 + (a * 2) % 10;
			sum2 += b;
		}
		if ((sum1 + sum2) % 10) printf("Invalid\n");
		else printf("Valid\n");
	}

	return 0;
}