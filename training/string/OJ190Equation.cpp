#include<iostream>
#include<stdio.h>
#include<string>
#include<stack>
using namespace std;

string postfixstr;
stack<int> userstack;

int priority(char x)
{
	if (x == '(')return 1;
	else if (x == '+'||x=='-')return 2;
	else if (x == '*'||x=='/')return 3;
}

void postfix(char x)
{
	if ((x <= '9') && (x >= '0'))
	{
		postfixstr.push_back(x);
	}
	else if ((x == '+') || x == '*' || x == '-' || x == '/')
	{
		if (userstack.empty() || priority(userstack.top())< priority(x))
			userstack.push(x);
		else
		{
			while ((!userstack.empty()) && priority(userstack.top()) >= priority(x))
			{
				postfixstr.push_back(userstack.top());
				userstack.pop();
			}
			userstack.push(x);
		}
	}
	else if (x == '(')userstack.push(x);
	else if (x == ')')
	{
		while ((!userstack.empty()) && (userstack.top() != '('))
		{
			postfixstr.push_back(userstack.top());
			userstack.pop();
		}
		if (!userstack.empty())userstack.pop();
	}
}
int main()
{
	int cases;
	cin >> cases;
	cin.ignore();
	string ignorefirstline;
	getline(cin, ignorefirstline);
	while (cases--)
	{
		string temp;
		postfixstr.clear();
		while (getline(cin, temp) && (!temp.empty()))
			postfix(temp[0]);
		while (!userstack.empty())
		{
			postfixstr.push_back(userstack.top());
			userstack.pop();
		}
		cout << postfixstr<<endl;
		if (cases)cout << endl;
	}
}