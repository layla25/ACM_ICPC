#include<iostream>
#include<queue>
using namespace std;
struct node
{
	int index;
	int distance;
	bool status;
	node(int i, int d,int s)
	{
		index = i;
		distance = d;
		status = s;
	}
	bool operator< (const node &x)const
	{
		return x.distance < distance;
	}
};
priority_queue<node>unsolved;
int d[502][2] = { 0 };
int map[502][502] = {0};
void init() 
{
	for (int i = 0;i < 502;i++)
	{
		d[i][0] = 1e9;
		d[i][1] = 1e9;
		for (int k = 0;k < 502;k++)
			map[i][k] = 0;
	}
}
void relax(int u, int v,bool state) 
{
	if (d[v][!state] > d[u][state] + map[u][v]) 
	{
		d[v][!state]= d[u][state]+ map[u][v];
		unsolved.push(node(v, d[v][!state], !state));
	}
}
int getDistance(int junctions)
{
	unsolved.push(node(0,0,1));
	d[0][1] = 0;//1 indicate walk
	while (!unsolved.empty())
	{
		node current = unsolved.top();
		unsolved.pop();
		for (int k = 0;k < junctions;k++)
		{
			if (map[current.index][k])//adj
			{
				relax(current.index, k, current.status);
			}
		}
	}
	return d[junctions - 1][1];
}
int main()
{
	int junctions = 0, roads = 0, testcase = 1;
	while (cin >> junctions >> roads)
	{
		init();
		for (int i = 0;i < roads;i++)
		{
			int from = 0, to = 0, distance = 0;
			cin >> from >> to >> distance;
			map[from][to] = distance;
			map[to][from] = distance;
		}
		cout << "Set #" << testcase++ << endl;
		int ans = getDistance(junctions);
		if (ans != 1e9)
			cout << ans << endl;
		else cout << "?" << endl;
	}
	return 0;
}
