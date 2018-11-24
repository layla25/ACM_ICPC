#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<limits>
#include<string>
#include<iostream>
#include<math.h>
using namespace std;
int getPA(string& s)
{
	int index = -1,size= s.size();
	int len = 0,last=0;
	for (int t = size - 2;t >= 0;--t) 
	{
		if (s[t] == s[t + 1])len++;
		else 
		{ 
			last = t;
			index = t + 1;
			break;
		}
	}
	for (int i = last, j = size-1;i >= 0;i--)
	{
		if (s[j] != s[i])continue;
		int k = j, m = i;
		while (k - m > 0)
		{
			if (s[k] != s[m])break;
			k--;m++;
		}
		if (k - m > 0)continue;
		else index = i;
		if ((i = 2 * i - j + len)<0)
			break;
	}
	return index - 1;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	string input;
	while (cin >> input)
	{
		int index = getPA(input);
		cout << input;
		if (index == -2)
			for (int i = input.size() - 2;i >= 0;--i)
				cout << input[i];
		while (index >= 0)
			cout << input[index--];
		cout << endl;
	}
}