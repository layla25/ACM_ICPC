#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<set>
#include<string>
#include<iostream>
using namespace std;
int main() 
{
	char c;
	cin.sync_with_stdio(true);
	set<string> dic;
	string s;
	while (cin.get(c)&&c!=EOF) 
	{
		if (c >= 'A'&&c <= 'Z')
			s += char(c - 'A' + 'a');
		else if (c >= 'a'&&c <= 'z')
			s += c;
		else 
		{
			dic.insert(s);
			s.clear();
		}
	}
	set<string>::iterator temp= dic.begin();
	++temp;
	for (set<string>::iterator it = temp;it != dic.end();++it)
		cout << *it<<endl;
}
