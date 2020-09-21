#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
bool findX(ll x)
{
    if (x == 0)
        return true;
    ll l = 1, r = 1000000;
    while (l <= r)
    {
        ll mid = (l + r) / 2;
        ll t = mid * mid * mid;
        if (t == x)
            return true;
        if (t > x)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return false;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll x, n;
        cin >> n;
        if (findX(n) == true)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}