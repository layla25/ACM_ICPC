#include<iostream>
#include<stdio.h>
using namespace std;
bool flag = true;
int equ() 
{
	int W1, L1, W2, L2;
	cin >> W1 >> L1 >> W2 >> L2;
	if (!W1) 
	{ 
		W1 = equ(); 
	}
	if (!W2) 
	{ 
		W2 = equ(); 
	}
	if ((W2*L2) != (W1*L1)) flag=false;
	else return W1+W2;
}
int main() 
{
	int cases;
	cin >> cases;
	while (cases--) 
	{
		equ();
		if(!flag)cout<<"NO"<<endl;
		else cout << "YES" << endl;
		if (cases) cout << endl;
		flag = true;
	}
	return 0;
}