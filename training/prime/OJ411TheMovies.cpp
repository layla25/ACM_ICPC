#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
int temp[100];
int main()
{
	int cases = 0;
	scanf("%d", &cases);
	set<unsigned long long>reserved;
	for (int i = 0;i < cases;i++)
	{
		int n = 0, m = 0, C = 0;
		unsigned long long choices = 0;
		reserved.clear();
		scanf("%d %d %d", &n, &m,&C);
		for (int j = 0;j < 2 * C;j++)
			scanf("%d", &(temp[j]));
		for (int k = 0;k < C;k++)
			reserved.insert((temp[k]-1)*m+temp[k+C]-1);
		int prev = -1,line=-1;
		for (set<unsigned long long>::iterator it = reserved.begin();it != reserved.end();it++)
		{
			int thisSeat = (*it) % m;
			int thisLine = (*it) / m;
			if (thisLine== line)//same line
				choices += thisSeat - prev > 2 ? thisSeat - prev - 2 : 0;
			else 
			{
				choices += (thisLine - line - 1)*(m-1LLU);
				if ((prev + line) != -2)//not first time
					choices += m - prev > 2 ? m - prev - 2 : 0;
				choices += thisSeat >= 2 ? thisSeat - 1 : 0;
			}
			line = thisLine;
			prev = thisSeat;
		}
		choices += m - prev > 2 ? m - prev - 2 : 0;
		choices += (n - line-1)*(m-1LLU);
		printf("Case #%d: %llu\n", i+1,choices);
	}
}