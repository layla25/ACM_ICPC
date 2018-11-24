#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int maze[301] = { 0 };
int everyLoop[301] = { 0 };
int ind = 0;
int constructTree(int a, int b, int c, int n, int x)
{
	if (maze[x])
		return maze[x];//exist before
	int gem = 0, next = x;
	everyLoop[ind++] = x;//temp store the temp tree
	maze[x] = 1;
	while (!maze[next = (a*next*next + b*next + c) % n])
	{
		everyLoop[ind++] = next;
		maze[next] = 1;
	}
	for (int k = 0;k < ind;k++) 
	{
		if (next == everyLoop[k]) 
		{
			for (int i = 0;i < ind;i++)
			{
				maze[everyLoop[i]] = ind - i;
			}
			return ind;
		}
	}
	int add = maze[next];
	for (int i = 0;i < ind;i++)
	{
		maze[everyLoop[i]] = ind + add - i;
	}
	return maze[everyLoop[0]];
}
int getgem(int a, int b, int c, int n)
{
	int max = 0;
	for (int i = 0;i < n;i++)
	{
		int currentGem = constructTree(a, b, c, n, i);
		max = max > currentGem ? max : currentGem;
		memset(everyLoop, 0, sizeof(everyLoop));
		ind = 0;
	}
	return max;
}
int main()
{
	int cases;
	cin >> cases;
	while (cases--)
	{
		int a = 0, b = 0, c = 0, n = 0;
		cin >> a >> b >> c >> n;
		memset(maze, 0, sizeof(maze));
		ind = 0;
		cout << getgem(a, b, c, n) << endl;
	}
	return 0;
}
