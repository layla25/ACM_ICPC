#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<cstring>
using namespace std;
bool grid[50][50];
int dp[50][50][50][50];
int main() 
{
	int N = 0;
	scanf("%d", &N);
	int total = N;
	while (N--) 
	{
		int r = 0;
		char input;
		memset(grid, 0, sizeof(grid));
		memset(dp, 0, sizeof(dp));
		scanf("%d", &r);
		int column = 0;
		int j = 0;
		input = getchar();
		for (int i = 0;i < r;i++)
		{
			while((input=getchar())&&(input!='\n'))
			{
				column++;
				if (input == '0')grid[i][j] = 1;
				j++;
			}
			j = 0;
		}
		column /= r;
		for (int k = 3;k <= r;k++) //length in y axis
		{
			for (int l = 3;l <= column;l++) //length in x axis
			{
				for (int m = 0;m <= r - k;m++) //y coordinate
				{
					for (int n = 0;n <= column - l;n++) //x coordinate
					{
						bool isDonut = 1;
						for (int t1 = n;t1 < n + l;t1++)
						{
							isDonut = isDonut&&grid[m][t1];//upper bound
							isDonut = isDonut&&grid[m+k-1][t1];//lower bound
							if (!isDonut)break;
						}
						for (int t3 = m+1;t3 < m + k-1;t3++) //reduce two edges
						{
							isDonut = isDonut&&grid[t3][n];//left bound
							isDonut = isDonut&&grid[t3][n+l-1];//right bound
							if (!isDonut)break;
						}
						dp[k][l][m][n] = dp[k - 2][l - 2][m + 1][n + 1] + isDonut;
						dp[k][l][m][n] = dp[k][l - 1][m][n]>dp[k][l][m][n] ? dp[k][l - 1][m][n] : dp[k][l][m][n];
						dp[k][l][m][n] = dp[k][l - 1][m][n+1]>dp[k][l][m][n] ? dp[k][l - 1][m][n+1] : dp[k][l][m][n];
						dp[k][l][m][n] = dp[k-1][l][m][n]>dp[k][l][m][n] ? dp[k-1][l][m][n] : dp[k][l][m][n];
						dp[k][l][m][n] = dp[k-1][l][m+1][n]>dp[k][l][m][n] ? dp[k-1][l][m+1][n] : dp[k][l][m][n];
						
					}
				}
			}
		}
		printf("Case #%d: %d",total-N, dp[r][column][0][0]);
		if (N)printf("\n");
	}
}