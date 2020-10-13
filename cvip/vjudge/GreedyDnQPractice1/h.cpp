#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double

ll p, q, r, s, t, u;

const ld eps = 1e-12;
const ld oo = 1;
ld check(ld x)
{
	return p * 1.0 * exp(-x) + q * 1.0 * sin(x) + r * cos(x) + s * (sin(x) / cos(x)) * 1.0 + t * x * x * 1.0 + u;
}
int main()
{
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(4);
	while (cin >> p >> q >> r >> s >> t >> u)
	{
		ld l = 0.0, r = 1.0, kq = 0;
		while (l - r <= eps)
		{
			ld mid = (l + r) / 2;
			kq = mid;
			if (check(mid) > eps)
				l = mid + eps;
			else
			{
				if (check(mid) < eps)
					r = mid - eps;
			}
		}
		if (check(0) * check(1) > eps)
			cout << "No solution";
		else
			cout << fixed << abs(kq);
		cout << "\n";
	}
}