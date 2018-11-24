#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<array>
#include<cstring>
using namespace std;
int dp[1005] = { 0 };
int year[1005] = { 0 };
vector<array<int, 5>>entries;
bool isInSameYear(array<int, 5>prev, array<int, 5>next)
{
	//m1 smaller than
	int m1 = prev.at(0), d1 = prev.at(1), h1 = prev.at(2), M1 = prev.at(3);
	int m2 = next.at(0), d2 = next.at(1), h2 = next.at(2), M2 = next.at(3);
	if (m1 < m2 || (m1 == m2&&d1 < d2) || (m1 == m2&&d1 == d2&&h1 < h2) || (m1 == m2&&d1 == d2&&h1 == h2&&M1 < M2))
		return true;
	else return false;
}
int main()
{
	int N = 0;
	while (scanf("%d", &N) && N != 0)
	{
		entries.clear();
		memset(dp, 0, sizeof(dp));
		memset(year, 0, sizeof(year));
		int first = -1, last = 0, indx = 0;
		for (int n = 0;n < N;n++)
		{
			int mm = 0, dd = 0, HH = 0, MM = 0;
			char sign;
			dp[indx] = N - indx;
			indx++;
			scanf("%2d:%2d:%2d:%2d %*s %c", &mm, &dd, &HH, &MM, &sign);
			if (sign == '+')
			{
				entries.push_back({ mm, dd, HH, MM,1 });
				if (first == -1)first = entries.size() - 1;
				last = entries.size() - 1;
			}
			else
				entries.push_back({ mm, dd, HH, MM,0 });
		}
		for (int i = 0;i < entries.size() - 1;i++)
		{
			if (isInSameYear(entries.at(i), entries.at(i + 1)))
				year[i + 1] = year[i];
			else year[i + 1] = year[i] + 1;
		}
		if (year[last] == year[entries.size() - 1]) 
		{
			dp[last] = 1;
			for (int m = last + 1;m < N;m++) 
				dp[m] = 0;
		}//
		else
		{
			last = entries.size() - 2;
			while (year[last] == year[entries.size() - 1])
			{
				dp[last] = 1;
				last--;
			}
		}
		for (int j = last;j >= first;j--)
		{
			for (int k = j + 1;k < N;k++)
			{
				if (year[k] == year[j] || ((year[k] == year[j] + 1) && (!isInSameYear(entries.at(j), entries.at(k)))))
					dp[j] = dp[j] < (dp[k] + 1) ? dp[j] : dp[k] + 1;
				else break;
				if (entries.at(k).at(4) == 1)break;
			}
		}
		printf("%d\n", dp[first]);
	}
	return 0;
}