#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
using namespace std;
int dp[1001][1001];
int main() 
{
	int N = 0;
	scanf("%d", &N);
	while (N--) 
	{
		char str1[1001],str2[1001];
		int i = 0, j = 0;
		memset(dp, 0, sizeof(dp));
		scanf("%s\n%s", str1, str2);
		for (i = 0;i < strlen(str1);i++) 
		{
			for (j = 0;j < strlen(str2);j++)
			{
				if (str1[i] == str2[j])
					dp[i + 1][j + 1] = dp[i][j] + 1;
				else if (dp[i][j + 1] >= dp[i + 1][j])
					dp[i + 1][j + 1] = dp[i][j + 1];
				else dp[i + 1][j + 1] = dp[i + 1][j];
			}
		}
		printf("%d\n",strlen(str1)+strlen(str2)-dp[strlen(str1)][strlen(str2)]);
	}
}