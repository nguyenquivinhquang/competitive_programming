#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<ll, ll>
using namespace std;

int testcase;

int main()
{
    int n, m, k;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n >> m >> k;
        int t = n / k;
        int a = min(m, t);
        m -= a;
        int b = (m + k - 2) / (k - 1);
        cout << a - b << endl;
    }
}