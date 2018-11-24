#include <iostream>
#include<stack>
#include<string>
using namespace std;

string postfixstr;
stack<int> userstack;
int priority(char x)
{
	if (x == '(')return 1;
	else if (x == '+' )return 2;
	else if (x == '*' )return 3;
}
void postfix(char x)
{
	if ((x <= '9') && (x >= '0'))
	{
		postfixstr.push_back(x);
	}
	if ((x <= 'F') && (x >= 'A'))
	{
		postfixstr.push_back(x - 'A' + '9' + 1);
	}
	else if ((x == '+') || x == '*')
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
	string equation;
	while (cin >> equation)
	{
		postfixstr.clear();
		for (int i = 0; i < equation.size(); i++)
		{
			postfix(equation.at(i));
		}
		while (!userstack.empty())
		{
			postfixstr.push_back(userstack.top()) ;
			userstack.pop();
		}
		//evaluate
		for (int i = 0; i < postfixstr.size(); i++)
		{
			if ((postfixstr.at(i) <= ('9'+6)) && (postfixstr.at(i) >= '0'))
			{
				userstack.push(postfixstr.at(i));
			}
			
			else
			{
				int num1, ans=0;
				num1 = userstack.top() - '0';
				userstack.pop();
				switch (postfixstr.at(i))
				{
				case '*':
					ans = num1*(userstack.top() - '0');
					break;
				case '+':
					ans = num1 + userstack.top() - '0';
					break;
				}
				userstack.pop();
				userstack.push(ans + '0');
			}
		}
		int ans = userstack.top() - '0';
		cout << hex << uppercase << ans << endl;
		userstack.pop();
	}
}