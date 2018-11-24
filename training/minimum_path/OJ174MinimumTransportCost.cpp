#include<iostream>
#include<string>
#include<stdio.h>
#include<sstream>
using namespace std;
int map[600][600] = {0};
int tax[600] = { 0 };
int parent[600][600] = { 0 };
void init() 
{
	for (int i = 0;i < 600;i++)
	{
		for (int k = 0;k < 600;k++)
		{	
			map[i][k] = 1e9;
			parent[i][k] = -1;
		}
		tax[i] = 0;
	}
}
void construct(int N) 
{
	for (int i = 0;i < N;i++)
	{
		for (int j = 0;j < N;j++)
		{
			for (int k = 0;k < N;k++)
			{
				if (map[j][i] + tax[i]+map[i][k]<map[j][k])
				{
					map[j][k] = map[j][i] + tax[i]+map[i][k];
					parent[j][k] = i;
				}
			}
		}
	}
}
void traceback(int from, int to)
{
	int fr = from - 1;
	int t = to - 1;
	if ((t = parent[fr][t])!=-1) 
	{
		traceback(from, t+1);
		cout << "-->" << t + 1;
		traceback(t+1, to);
	}
}
void display(int from, int to) 
{
	int cost = map[from-1][to-1];
	cout << "From " << from << " to " << to << " :" << endl;
	cout << "Path: "<<from;
	if (from == to)
	{
		cout << endl << "Total cost : 0"  <<endl;
		return;
	}
	traceback(from, to);
	cout << "-->" << to<<endl;
	cout << "Total cost : " << cost << endl;
}

int main() 
{
	int M=0;
	cin >> M;
	cin.ignore();
	while (M--) 
	{
		init();
		int N=0;
		char space;
		while (1) 
		{
			scanf("%d%c", &(map[0][N++]), &space);
			if (map[0][N - 1] == -1)map[0][N - 1] = 1e9;
			if (space == '\n')
				break;
		}
		for (int i = 1;i < N;i++) 
			for (int j = 0;j < N;j++)
			{
				cin >> map[i][j];
				if (map[i][j] == -1)map[i][j] = 1e9;
			}
		for (int k = 0;k < N;k++)
			cin >> tax[k];
		construct(N);
		string line;
		cin.ignore();
		bool isFirstline = 1;
		while (getline(cin,line)&&!line.empty()) 
		{
			if (isFirstline)
				isFirstline = 0;
			else
				cout << endl;
			int from=0, to=0;
			istringstream iss(line);
			iss >> from>>to;
			display(from,to);
		}
		if (M)cout << endl;
	}
	return 0;
}