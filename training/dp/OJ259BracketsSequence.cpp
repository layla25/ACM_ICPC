#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
#include<iostream>
using namespace std;
int dp[101][101];
int main()
{
	int N = 0;
	char str[101];
	scanf("%d", &N);
	cin.ignore();
	while (N--)
	{
		cin.ignore();
		cin.getline(str, 105);
		memset(dp, 0, sizeof(dp));
		for (int x = 0;x < strlen(str);x++)
			dp[x][x] = 2;
		for (int i = 1;i < strlen(str);i++) 
		{
			for (int j = 0;j < strlen(str)-i;j++)
			{
				if (str[j] == '('&&str[j+i] == ')' || str[j] == '['&&str[j+i] == ']')
				{
					if(i!=1)
						dp[j][j+i] = dp[j + 1][j+i- 1]+2;
					else dp[j][j + i] = 2;
				}
				else 
				{
					if (i != 1)
						dp[j][j+i] = dp[j + 1][j+i - 1] + 4;
					else
						dp[j][j+i] = 4;
				}
				for (int k = j;k < j + i;k++) 
				{
					if (dp[j][k] + dp[k + 1][j + i] < dp[j][j + i])
						dp[j][j + i] = dp[j][k] + dp[k + 1][j + i];
				}
			}
		}
		printf("%d\n", dp[0][strlen(str)-1]);
	}
}