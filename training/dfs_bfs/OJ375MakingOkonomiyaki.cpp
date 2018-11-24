#include<iostream>
#include<array>
#include<cstring>
#include<queue>
using namespace std;
int fourjugs[4] = {0};
int target = 0;
queue<array<int, 5>>node;
bool visit[26][26][26][26] = { 0 };
bool dovisit(array<int,5> x) 
{
	return visit[ x[0] ] [ x[1] ] [ x[2] ] [ x[3] ];
}
void markvisited(array<int, 5> current)
{
	if (!dovisit(current))
	{
		visit[current[0]][current[1]][current[2]][current[3]] = 1;
		node.push({ current[0], current[1], current[2], current[3], current[4] + 1 });
	}
}
bool pour(int x, int y,array<int,5>current)//x to y 
{
	if ((current[x] + current[y]) <= fourjugs[y])
	{
		current[y] += current[x];
		current[x] = 0;
	}
	else
	{
		current[x] += current[y] - fourjugs[y];
		current[y] = fourjugs[y];
	}
	if (current[x] == target || current[y] == target)
		return true;
	markvisited(current);
	return false;
}
void fill(int x, array<int, 5>current)
{
	current[x] = fourjugs[x];
	markvisited(current);
}
void empty(int x, array<int, 5>current)
{
	current[x] = 0;
	markvisited(current);
}
int getstep() 
{
	for (int i = 0;i < 4;i++)
	{
		if (fourjugs[i] == target)
		{
			return 1;
		}
	}
	visit[0][0][0][0] = true;
	node.push({ 0,0,0,0,0});
	while (!node.empty()) 
	{
		array<int,5> next = node.front();
		node.pop();
		for (int i = 0;i < 4;i++)
		{
			fill(i, next);
			empty(i, next);
			for (int k = 0;k < 4;k++)
			{
				if ((k!=i)&&pour(i, k, next))
					return next[4]+1;
			}
		}
	}
	return -1;
}
void init() 
{
	while (!node.empty())
		node.pop();
	memset(visit, 0, sizeof(visit));
}
int main()
{
	int input=0,times = 4,max=0;
	while (cin >> input) 
	{
		if (times--) 
			fourjugs[3 - times] = input;
		else 
		{
			target = input;
			init();
			cout<< getstep()<<endl;
			times = 4;
		}
	}
	return 0;
}