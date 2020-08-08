#include <bits/stdc++.h>
#define mod %
#define module 1000000007
#define ll long long
using namespace std;
int c = 0;
ll Fast_frac(ll x)
{
    c++;
    if (x == 1)
        return 2;
    ll t;
    if (x & 1)
    {
        t = Fast_frac(x / 2);
        return (t * t * 2) mod module;
    }
    else
    {
        t = Fast_frac(x / 2);
        return (t * t) mod module;
    }
}

int main()
{
    int t = 0;
    ll x;
    cin>>t;
    for (int i = 1; i <= t; i++)
    {
        cin>>x;
        cout << Fast_frac(x) - 1 << endl;
    }
}
