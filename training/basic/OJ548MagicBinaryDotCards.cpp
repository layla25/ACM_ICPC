#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;

int main() 
{
	long long A = 0, B = 0;
	while (scanf_s("%lld%lld", &A, &B) != EOF)
	{
		vector<int>store;
		long long sum = 0;
		if (A == B) { printf("%ld",A);continue; }
		long long x=1;
		int i = 0;
		do {
			x = exp2(++i);
		} while (B / x);
		x /= 2;
		i -= 1;
		store.push_back(i);
		while (1) {
			if (((A > x) && (B > x))||(A==x))
			{
				x += exp2 (--i);
				store.push_back(i);
			}
			else if ((A < x) && (B < x))
			{
				x -= exp2(--i);
				store.pop_back();
				store.push_back(i);
			}
			else break;
		}
		for (int i = 0;i < store.size()-1;i++)
		{
			sum += exp2(store[i]);
		}
		sum += exp2(store[store.size() - 1]+1)-1;
		printf("%lld", sum);
	}
	return 0;
}