#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<queue>
#include<iostream>
#include<cstring>
using namespace std;
struct node 
{
	int index;
	int distance;
	int status;
	node(int i, int d, int s) 
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
char trapType[1005];
int trapValue[1005];
int d[1005][13];
int map[1005][1005];
void init() 
{
	for (int i = 0;i < 1005;i++)
		for (int j = 0;j < 13;j++)
			d[i][j] = 1e9;
	memset(trapValue, 0, sizeof(trapValue));
	memset(trapType, 0, sizeof(trapType));
	memset(map, 0, sizeof(map));
}
void relax(int u,int v,int status) 
{
	int v_state = 0;
	switch (trapType[v]) 
	{
	case '+':
		v_state = (status + trapValue[v]) % 12;
		break;
	case '-':
		v_state = (status - trapValue[v]) % 12;
		break;
	case '*':
		v_state = ((status+1)*trapValue[v]-1) % 12;
		break;
	case '=':
		v_state = (trapValue[v]-1)%12;
		break;
	default:
		v_state = status;
	}
	if (d[v][v_state] > d[u][status] + map[u][v]) 
	{
		d[v][v_state] = d[u][status] + map[u][v];
		unsolved.push(node(v,d[v][v_state],v_state));
	}
}
void calculate(int ini_room,int ini_ring, int final_room,int final_ring,int N) 
{
	unsolved.push(node(ini_room,0,ini_ring-1));
	d[ini_room][ini_ring-1] = 0;
	while (!unsolved.empty()) 
	{
		node current = unsolved.top();
		unsolved.pop();
		for (int k = 1;k <= N;k++) 
		{
			if (map[current.index][k]) 
			{
				relax(current.index, k, current.status);
			}
		}
	}
	if (d[final_room][final_ring - 1] == 1e9)
		printf("Pray!\n");
	else printf("%d\n",d[final_room][final_ring-1]);//

}
int main() 
{
	int rm_num = 0, cor_num = 0, trp_num = 0;
	int rm_no_ent, init_ring = 0, rm_no_tre = 0, open_ring = 0;
	while (cin>>rm_num) 
	{
		init();
		scanf("%d %d %d %d %d %d", &cor_num, &trp_num, &rm_no_ent, &init_ring, &rm_no_tre, &open_ring);
		while (cor_num--) 
		{
			int rm_num_0 = 0, rm_num_1 = 0, len = 0;
			scanf("%d %d %d", &rm_num_0, &rm_num_1, &len);
			map[rm_num_0][rm_num_1] = len;
			map[rm_num_1][rm_num_0] = len;
		}
		while (trp_num--) 
		{
			int rm_number=0, n = 0;
			char trp_type;
			scanf("%d %c %d", &rm_number, &trp_type, &n);
			trapType[rm_number] = trp_type;
			trapValue[rm_number] = n;
		}
		calculate(rm_no_ent,init_ring,rm_no_tre,open_ring,rm_num);
	}
	return 0;
}