#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<math.h>
#include<set>
using namespace std;
int sieve[64];
bool base[65536];
unsigned long long power(unsigned long long base, int x) 
{
	if (x == 1)return base;
	if (x & 1)//odd
	{
		x -= 1;
		return base*power(base*base, x / 2);
	}
	else 
		return power(base*base, x / 2);
}
int main() 
{
	vector<int>prime;
	vector<int>nonprime;
	for (int i = 2;i < 64;i++) 
	{
		if (!sieve[i])prime.push_back(i);
		else nonprime.push_back(i);
		for (int j = 0;j < prime.size()&&i*prime[j] < 64 ;j++)
		{
			sieve[i*prime[j]] = true;
		}
	}
	unsigned long long maxIndex = 65536;
	set<unsigned long long> ans;
	for (int j = 2;j < maxIndex;j++) 
	{
		if (base[j])continue;
		for (int k = 0;k < nonprime.size();k++) 
		{
			if(nonprime[k]<64.0*log(2) / log(j))
				ans.insert(power(j,nonprime[k]));
		}
		for (int t = 2;t < log(65536)/log(j);t++)
			base[(int)pow(j, t)] = true;
	}
	printf("1\n");
	for (set<unsigned long long>::iterator it=ans.begin();it!=ans.end();it++)
		printf("%llu\n", *it);
	return 0;
}