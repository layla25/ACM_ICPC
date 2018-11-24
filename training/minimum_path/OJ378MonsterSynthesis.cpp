#include<iostream>
using namespace std;
int map[105][105] = { 0 };
int level[105][105][2] = { 0 };
void init() 
{
	for (int i = 0;i < 105;i++)
	{
		for (int k = 0;k < 105;k++)
		{	
			map[i][k] = 1e9;
			level[i][k][0] = 0;
			level[i][k][1] = 0;
		}
	}
}
void relax(int N,int M) 
{
	for (int i = N-1;i >= 0;i--)
		for (int j = N-1;j >= 0;j--)
			for (int k = N-1;k >=0;k--)
				if ((map[j][i] + map[i][k] - map[i][i] < map[j][k])&& level[i][k][0]>= level[j][i][1]-M&&level[i][k][1] <= level[j][i][0] + M)
				{
					map[j][k] = map[j][i] + map[i][k] - map[i][i];
					level[j][k][0] = level[j][i][0] < level[i][k][0] ? level[j][i][0] : level[i][k][0];
					level[j][k][1] = level[j][i][1] > level[i][k][1] ? level[j][i][1] : level[i][k][1];
				}
}
int main() 
{
	int M=0,N=0;
	while (cin >> M >> N)
	{
		init();
		for (int i = 0;i < N;i++)
		{
			int rules = 0, money = 0;
			cin >> money >> level[i][i][0] >> rules;
			for (int k = 0;k < N;k++)
				map[k][i] = money;
			while (rules--)
			{
				int number = 0, price = 0;
				cin >> number >> price;
				map[number - 1][i] = price;
			}
		}
		for (int k = 0;k < N;k++)
		{
			for (int m = 0;m < N;m++)
			{
				if (m != k)
				{
					map[k][m] += map[k][k];
					if (level[k][k][0]>level[m][m][0] + M || level[k][k][0] < level[m][m][0] - M) 
					{
						level[k][m][1] = level[m][m][0];
						level[k][m][0] = level[m][m][0];
					}
					else if (level[k][k][0]>level[m][m][0])
					{
						level[k][m][1] = level[k][k][0];
						level[k][m][0] = level[m][m][0];
					}
					else
					{
						level[k][m][0] = level[k][k][0];
						level[k][m][1] = level[m][m][0];
					}
				}
			}
		}
		//it cant get everyone
		relax(N,M);
		int min = 1e9;
		for (int m = 0;m < N;m++)
			min = min < map[m][0] ? min : map[m][0];
		cout << min<<endl;
	}
	return 0;
}