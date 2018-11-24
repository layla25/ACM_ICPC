#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
const int N = 100000000;
int sieve[(N >> 5) + 1];  
int  GET(int x) { return sieve[x >> 5] >> (x & 31) & 1; }
void SET(int x) { sieve[x >> 5] |= 1 << (x & 31); }

void eratosthenes()
{
	register int i, j, k;
	int sqrt_N = sqrt(N);
	SET(0); SET(1);
	for (i = 2; i <= sqrt_N; i++)
		if (!GET(i))
			for (k = N / i, j = i*k; k >= i; k--, j -= i)
				if (!GET(k))
					SET(j);
}

int main()
{
	int x = 0;
	eratosthenes();
	while (scanf("%d", &x) != EOF)
	{
		if (x & 1)//odd 
		{
			if (!GET(x - 2) && x >= 5)
				printf("%d is the sum of 2 and %d.\n", x, x - 2);
			else
				printf("%d is not the sum of two primes!\n", x);
		}
		else
		{
			int mid = x / 2, left = 0, right = 0;
			if (mid != (mid | 1)) //14
				left = mid - 1, right = mid + 1;
			else //13
				left = mid - 2, right = mid + 2;
			while ((GET(left)|| GET(right)) && left >= 2)
				left -= 2, right += 2;
			if (left<2)
				printf("%d is not the sum of two primes!\n", x);
			else
				printf("%d is the sum of %d and %d.\n", x, left, right);
		}
	}
}