#include<stdio.h>
#include<iostream>
#include<iomanip>
#include <vector>
using namespace std;
int main() 
{
	while (1) 
	{
		vector<int>lights;
		int temp = 0;
		float max=0;
		bool flag = true;
		scanf("%d", &temp);
		if (temp != 0) 
		{ 
			lights.push_back(temp); 
			max = temp; 
		}
		while (scanf("%d", &temp) && temp != 0) 
		{
			lights.push_back(temp);
			max = max < temp ? max : temp;
		}
		if (lights.size()== 0) break;
		while (1) 
		{
			int i;
			for (i = 0;i < lights.size();i++)
			{
				int remain = ((int)(2 * max)) % (2 * lights[i]);
				if (!(remain < (lights[i] - 5)))
				{
					max=max+lights[i]-remain/2;
					break;
				}
			}
			if (max > 9000)
			{
				printf("Signals fail to synchronise in 5 hours\n");
				flag = false;
				break;
			}
			if (i == lights.size())break;
		}
		if (!flag)continue;
		int time = (int)(2 * max);
		cout << setfill('0')<<setw(2);
		cout << time / 3600 << ":";
		cout << setfill('0') << setw(2);
		cout << (time / 60 - time / 3600 * 60) << ":";
		cout << setfill('0') << setw(2);
		cout<<(time - time / 60 * 60)<<endl;
	}
	return 0;
}