#include<iostream>
#include<string>
using namespace std;
int main() 
{
	int cases;
	string chains;
	int growth;
	cin >> cases;
	while (cases--)
	{
		cin >> chains;
		if (chains == "A") 
		{
			cout << "SIMPLE" << endl;
			continue;
		}
		if ((chains.back() == 'A') && (chains.front() == 'B'))
		{
			growth = 0;
			chains.pop_back();
			chains.erase(chains.begin(), chains.begin() + 1);
		}
		else if (chains.back() == 'B')
		{
			growth = 1;
			chains.pop_back();
			if (chains.back() == 'A')chains.pop_back();
			else 
			{
				cout << "MUTANT" << endl;
				continue;
			}
		}
		//to record the growth
		while (chains.size() >1) 
		{
			if ((chains.back() == 'A') && (chains.front() == 'B')) 
			{
				chains.pop_back();
				chains.erase(chains.begin(), chains.begin() + 1);
			}
			else if (chains.back() == 'B') 
			{
				chains.pop_back();
				if (chains.back() == 'A')chains.pop_back();
				else break;
			}
			else break;
		}
		if ((chains.size() > 1) || chains.size() == 0)cout << "MUTANT" << endl;
		if (chains == "A") 
		{ 
			if(growth)cout << "FULLY-GROWN"<<endl;
			else cout << "MUTAGENIC" << endl;
		}
	}
	return 0;
}