#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string>
#include<iostream>
using namespace std;
int occur = 0;
int fail(string& p,int begin)
{
	int failure[1010];
	int maxLen = -1;
	for (int i = 1, j = failure[0] = -1; i<p.size()-begin; ++i)
	{
		while (j >= 0 && p[j + 1+begin] != p[i+begin])
			j = failure[j];
		if (p[j + 1+begin] == p[i+begin]) j++;
		failure[i] = j;
		if (j > maxLen) 
		{
			maxLen = j;
			occur = 2;
		}
		else if (j == maxLen) 
		{
			occur++;
		}
	}
	return maxLen;
}
int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	int cases;
	cin >> cases;
	while (cases--)
	{
		string input;
		cin >> input;
		int maxLen = -2, begin = -2,occurance = -1;
		for (int i = 0;i < input.size();i++) 
		{
			int len = fail(input, i);
			if (len > maxLen||(len==maxLen&&input.substr(begin,maxLen+1).compare(input.substr(i,len+1))>0))
			{
				begin = i;
				maxLen = len;
				occurance = occur;
			}
		}
		if (maxLen == -1)
			cout << "No repetitions found!" << endl;
		else
			cout << input.substr(begin, maxLen+1) << " "<<occurance << endl;
	}
}