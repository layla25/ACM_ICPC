#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
using namespace std;
int execute[25][25];
int dp[25][25];
char str1[25], str2[25];
void doExecute(int len1, int len2)
{
	if (len1 ==0 && len2 ==0)return;
	switch (execute[len1][len2])
	{
	case 1:
		doExecute(len1 - 1, len2 - 1);
		printf("C%c%02d", str2[len2-1], len2);
		return;
	case 2:
		doExecute(len1, len2-1);
		printf("I%c%02d", str2[len2-1], len2);
		return;
	case 3:
		doExecute(len1-1, len2 );
		printf("D%c%02d", str1[len1-1], len2 + 1);
		return;
	default:
		doExecute(len1 - 1, len2 - 1);
		return;
	}
}
int main()
{
	while (scanf("%s", str1) && str1[0] != '#')
	{
		scanf("%s", str2);
		memset(dp, 1e9, sizeof(dp));
		memset(execute, 0, sizeof(dp));
		for (int a = 0;a <= strlen(str2);a++)
		{
			dp[0][a] = a;
			execute[0][a] = 2;//insert
		}
		for (int b = 1;b <= strlen(str1);b++)
		{
			dp[b][0] = b;
			execute[b][0] = 3;//delete
		}
		for (int i = 1;i <= strlen(str1);i++)
		{
			for (int j = 1;j<=strlen(str2);j++)
			{
				bool equal = (str1[i-1] == str2[j-1]);
				if ((dp[i - 1][j - 1] +1- equal <=dp[i][j - 1]+1 )&& (dp[i - 1][j - 1]+1 - equal <= dp[i - 1][j]+1))
				{
					dp[i][j] = dp[i - 1][j - 1] + (1 - equal);
					if(!equal)
						execute[i][j] = 1;//change
					else execute[i][j] = -1;//dont do anything
				}
				else if ((dp[i][j - 1]<= dp[i - 1][j]))
				{
					dp[i][j] = dp[i][j - 1] + 1;
					execute[i][j] = 2;//insert
				}
				else 
				{
					dp[i][j] = dp[i - 1][j] + 1;
					execute[i][j] = 3;//delete
				}
			}
		}
		doExecute(strlen(str1), strlen(str2));
		printf("E\n");
	}
}
