#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
vector<int>domino[10005];
bool visited[10005] = { 0 };
int knock(int x) 
{
	int cnt=0;
	if (visited[x])
		return 0;
	else visited[x] = 1;
	for (int i = 0;i < domino[x].size();i++)
		cnt+=knock(domino[x][i]);
	return cnt+1;
}
int main() 
{
	int cases=0;
	cin >> cases;
	while (cases--) 
	{
		int n = 0, m = 0, l = 0;
		cin >> n >> m >> l;
		memset(visited, 0, sizeof(visited));
		for (int i = 0;i < 10005;i++) 
		{
			domino[i].clear();
		}
		while (m--) 
		{
			int x = 0, y = 0;
			cin >> x >> y;
			domino[x].push_back(y);
		}
		int count = 0;
		while (l--) 
		{
			int knocked=0;
			cin >> knocked;
			count+=knock(knocked);
		}
		cout << count << endl;
	}
	return 0;
}