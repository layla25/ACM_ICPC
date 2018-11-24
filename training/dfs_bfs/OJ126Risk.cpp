#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
vector<int>links[20];
bool visited[20] = { 0 };
int distancerecord[20] = { 0 };
queue<int>nodes;
void constructTree(int target, int boardsharer) 
{
	links[target - 1].push_back(boardsharer-1);
	links[boardsharer - 1].push_back(target-1);
}
void init()
{
	while (!nodes.empty())
		nodes.pop();
	memset(distancerecord, 0, sizeof(distancerecord));
	memset(visited, 0, sizeof(visited));
}
int compute(int from, int to) 
{
	nodes.push(from);
	visited[from-1] = true;
	while (!nodes.empty()) 
	{
		int current = nodes.front();
		visited[current - 1] = true;
		nodes.pop();
		for (int i = 0;i < links[current - 1].size();i++) 
		{
			if (links[current - 1][i] == to-1)
				return distancerecord[current - 1] + 1;
			if (visited[links[current - 1][i]] != true)
			{
				visited[links[current - 1][i]] = true;
				nodes.push(links[current - 1][i] + 1);
				distancerecord[links[current - 1][i]] = distancerecord[current - 1] + 1;
			}
		}
	}
}
void display(int from, int to, int distance) 
{
	cout.width(2);cout << right<<from;
	cout.width(4);cout << " to ";
	cout.width(2);cout << right << to;
	cout.width(2);cout << ": ";
	cout<<distance<<endl;
}
int main() 
{
	int input = 0;
	int lines = 19;
	int testcases = 1;
	while (cin >> input) 
	{
		if (!(lines--)) 
		{
			cout << "Test Set #" << testcases++ << endl;
			while (input--) 
			{
				int from = 0, to = 0;
				cin >> from >> to;
				init();
				int x = compute(from, to);
				display(from,to,x);
			}
			cout << endl;
			for (int i = 0;i < 20;i++)
				links[i].clear();
			lines = 19;
			continue;
		}
		while (input--) 
		{
			int temp = 0;
			cin >> temp;
			constructTree(19 - lines, temp);
		}
	}
	return 0;
}