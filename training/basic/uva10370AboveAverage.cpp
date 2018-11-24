# include <iostream>
# include <vector>
# include <iomanip>
using namespace std;
int main()
{	
	int c,n;
	vector<double>percentage;
	while (cin >> c)//c stores number of sets
	{
		for (int i = 1; i <= c; i++)  //this loop for c number of sets
		{
			vector<int> a;
			double per, numabove = 0, sum = 0;
			cin >> n;
			if (n == '/n')
			{
				n = 0;
			}
			for (int i = 0; i < n; i++)
			{
				int temp;
				cin >> temp;
				a.push_back(temp);
				sum += temp;
			}
			float ave = sum / n;
			for (int i = 0; i < n; i++)
			{
				if (a[i] > ave){ numabove++; }
			}
			per = numabove / n * 100;
			percentage.push_back(per);
		}
		for (int i = 0; i <c; i++)
		{ 
			cout << fixed <<setprecision(3) <<percentage[i] << "%"<<endl; 
		}
	}
}
