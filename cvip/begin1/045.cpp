#include <iostream>
#include <cmath>

using namespace std;

int an(int n)
{
	int a = sqrt(n);
	for (int x = 1; x <= a; x++)
		for (int y = 1; y <= a; y++)
			if (x * x + y * y == n)
			{
				cout << "Yes" << endl;
				return 0;
			}
	cout<<"No"<<endl;
}
int main()
{
	int t;
	cin >> t;
	int x, y;
	int n;
	for (int i = 1; i <= t; i++)
	{
		cin >> n;
		an(n);
	}
}
