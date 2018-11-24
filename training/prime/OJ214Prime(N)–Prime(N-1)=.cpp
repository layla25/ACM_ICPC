#define _CRT_SECURE_NO_WARNINGS	
#define N 1299709
#include<stdio.h>
#include<vector>
using namespace std;
bool sieve[N];
int main() 
{
	vector<int>prime;
	for (int i = 2;i < N;i++)
	{
		if (!sieve[i])prime.push_back(i);
		for (int j = 0;j < prime.size()&&i*prime[j] < N;j++)
			sieve[i*prime[j]] = true;//not prime
	}
	int x = 0;
	while (scanf("%d", &x) && x) 
	{
		if (!sieve[x])
			printf("0\n");
		else 
		{
			int i=x,j=x;
			while (i--)
				if (!sieve[i])
					break;
			while (j++)
				if (!sieve[j])
					break;
			printf("%d\n",j-i);
		}
	}
}
