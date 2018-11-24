#include <iostream>
#include <string>
#include <map>
#include<stack>
using namespace std;


string postfixstr;
stack<char> userstack;
map<char, bool>variables;
map<char, bool>::iterator it;


int priority(char x)
{
	if (x == '(')return 1;
	else if (x == '+')return 2;
	else if (x == '&')return 3;
	else if (x == '!')return 4;
}
void postfix(char x)
{

	if ((x >= 'A') && (x <= 'z'))
	{
		postfixstr.push_back(x);
		variables[x] = true;
	}
	else if (x == '+' || x == '&' || x == '!')
	{
		if (userstack.empty() || priority(userstack.top())< priority(x))//lower prior
			userstack.push(x);
		else
		{
			while (!userstack.empty() && (priority(userstack.top()) >= priority(x)))
			{
				postfixstr.push_back(userstack.top());
				userstack.pop();
			}
			userstack.push(x);
		}
	}
	else if (x == '(')
		userstack.push(x);
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
bool calculate()
{
	bool flag = false;
	for (int i = 0; i < postfixstr.size(); i++)
	{
		if ((postfixstr[i] <= 'z') && (postfixstr[i] >= 'A'))
		{
			userstack.push(variables[postfixstr[i]]);
		}
		else
		{
			bool ans = 0;
			char top = userstack.top();

			switch (postfixstr[i])
			{
			case '!':
				ans = !(top);
				break;
			case '&':
				userstack.pop();
				ans = top && userstack.top();
				break;
			case '+':
				userstack.pop();
				ans = top || userstack.top();
				break;
			}
			userstack.pop();
			userstack.push(ans);
		}
	}
	flag = userstack.top();
	userstack.pop();
	return flag;
}
bool recursion(int x)
{
	if (!calculate())
	{
		if (x == 1) return false;
		if (it == variables.end()) { return false; }
		it->second = true;
		it++;
		if (recursion(x - 1))
			return true;
		it--;
		if (it == variables.end()) { return false; }
		it->second = false;
		it++;
		if (recursion(x - 1))
			return true;
	}
	else
		return true;
	return false;
}
int main()
{
	string equation;
	while (getline(cin, equation))
	{
		postfixstr.clear();
		variables.clear();
		for (int i = 0;i < equation.length();i++)
		{
			if (equation[i] != ' ')
				postfix(equation[i]);
		}
		while (!userstack.empty())
		{
			postfixstr.push_back(userstack.top());
			userstack.pop();
		}
		it = variables.begin();
		if (recursion(variables.size()))
			cout << "true" << endl;
		else cout << "false" << endl;
	}
}