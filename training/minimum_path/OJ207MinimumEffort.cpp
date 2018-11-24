#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
using namespace std;
struct node
{
	int len;
	int index;
	node(int l, int i)
	{
		len = l;
		index = i;
	}
	bool operator<(const node&other)const
	{
		return other.len<len;
	}
};
map<string,int>places;
map<string, int>::iterator it;
priority_queue<node>unsolved;
int matrix[204][204];
vector<string>answer;
int d[204];;
int parent[204];
string find(int index) 
{
	for (it = places.begin();it != places.end();it++)
		if (it->second == index)
			return it->first;
}
void init() 
{
	places.clear();
	for (int i = 0;i < 204;i++) 
		for (int j = 0;j < 204;j++)
			matrix[i][j] = 0;
}
int calculate(int N,string from,string to,int& begin) 
{
	for (int i = 0;i < 204;i++)
	{
		d[i] = 1e9;
		parent[i] = -1;
	}
	unsolved.push(node(0,places.at(from)));
	d[places.at(from)]=0;
	while (!unsolved.empty()) 
	{
		node current = unsolved.top();
		unsolved.pop();
		for (int i = 0;i < N;i++)
		{
			if (matrix[current.index][i])
			{
				if (d[i]>d[current.index]+matrix[current.index][i])
				{
					d[i] = d[current.index] + matrix[current.index][i];
					unsolved.push(node(d[i],i));
					parent[i] = current.index;
				}
			}
		}
	}
	int next = places.at(to);
	int length = 0;
	while (parent[next] != -1) 
	{
		next = parent[next];
		answer.push_back(find(next));
		length++;
	}
	reverse(answer.begin()+begin, answer.begin()+begin+length);
	begin += length;
	return d[places.at(to)];
}
int main() 
{
	int N = 0;
	while (cin >> N) 
	{
		int begin = 0;
		cin.ignore();
		string place;
		int ind=0;
		init();
		for (int k = 0;k < N;k++)
		{
			getline(cin, place);
			places.insert(pair<string,int>(place,ind++));
		}
		int P = 0;
		cin >> P;
		cin.ignore();
		while (P--) 
		{
			string line;
			char from[18],to[18]; 
			int gocost = 0, backcost = 0;
			getline(cin, line);
			sscanf(line.c_str(),"%[^:]:%[^1-9]%d %d",&from,&to,&gocost,&backcost);
			string to_s = to;
			to_s = to_s.substr(0, to_s.size() - 1);
			matrix[places.at(from)][places.at(to_s)] = gocost;
			if(backcost!=0)matrix[places.at(to_s)][places.at(from)] = backcost;
		}
		cout << calculate(N, "office", "hall",begin) + calculate(N, "hall", "office",begin) << endl;
		reverse(answer.begin(),answer.end());
		while (!answer.empty()) 
		{
			cout << answer.back() << " -> ";
			answer.pop_back();
		}
		cout << "office" << endl << endl;
	}
	return 0;
}