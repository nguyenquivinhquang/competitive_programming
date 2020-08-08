//https://vjudge.net/contest/358723#problem
#include <bits/stdc++.h>
#define ll long long
#define pp pair<ll, ll>
#define maxn 1000000
#define mod %
using namespace std;

vector<pp> a(maxn+1);
pp c[maxn];
ll n, cost;
pp temp;

ll cal(ll h)
{
    cost=0;
    for (int i = 1; i <= n; i++)
        cost += abs(h - a[i].second) * a[i].first;
    return cost;
}
double quangdeptraicutevaidai(double left, double right) {

	int lim = 100;

	for (int i = 0; i < lim; i++) {

		double x1 = left + (right - left) / 3.0;
		double x2 = right - (right - left) / 3.0;

		if (cal(x1) < cal(x2)) right = x2;
		else left = x1;
	}
	return cal(left);
}
int main()
{
    int testcase;
    int b[10001];
    cin >> testcase;
    freopen("input.txt","r",stdin);
    while (testcase--)
    {
        // first: cost; second: height
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> b[i];
        int t;
        for (int i = 1; i <= n; i++)
        {
            cin >> t;
            temp = {t, b[i]};
            a[i]=temp;
        }
        ll kq=quangdeptraicutevaidai(0,50000);
        cout<<kq<<endl;
    }
}