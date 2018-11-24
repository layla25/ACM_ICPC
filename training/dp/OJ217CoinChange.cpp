#include<iostream>
#include<cstring>
using namespace std;
int counts[7490] = {0};
int main() 
{
	int num = 0;
	int coins[5] = {1,5,10,25,50};
	while (cin >> num) 
	{
		memset(counts, 0, sizeof(counts));
		counts[0] = 1;
		for (int i = 0;i < 5;i++)
			for (int j = 0;j <= num-coins[i];j++)
				counts[j+coins[i]]+=counts[j];
		cout << counts[num] << endl;
	}
	return 0;
}
