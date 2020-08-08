#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll compute(int n)
{
	ll s = 0, i = 0;
	while (s <= n)
	{
		i++;
		if (s + (i - 1) + i * 2 > n)
			return n - s;
		s = s + (i - 1) + i * 2;
	}
}
int main()
{
	int n, testcase;
	cin >> testcase;
	while (testcase--)
	{
		cin >> n;
		ll s = 0, ways;
		while (n > 1)
		{
			n = compute(n);
			s++;
		}
		cout << s << endl;
	}
}