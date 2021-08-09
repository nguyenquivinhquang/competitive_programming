#include <bits/stdc++.h>
#define maxn 10000
#define mod %
#define ll long long
using namespace std;
bool cal(ll a, ll b)
{
    ll x, y;
    if ((a + b) mod 3 != 0)
        return false;
    y = b - (a + b) / 3;
    if (y < 0)
        return false;
    ll t = (a - b) + (a + b) / 3;
    if (t < 0 || t mod 2 == 1)
        return false;
    return true;
}
int main()
{
    ll testcase;
    ll a, b;
    cin >> testcase;
    while (testcase--)
    {
        cin >> a >> b;
        if (cal(a, b) == true)
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}