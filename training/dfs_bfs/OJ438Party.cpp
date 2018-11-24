#include<iostream>
using namespace std;
int main() 
{
	int cases;
	cin >> cases;
	while (cases--) 
	{
		unsigned int number;
		cin >> number;
		if (number >= 3)cout << number - 2;
		else cout << 0;
	}
}