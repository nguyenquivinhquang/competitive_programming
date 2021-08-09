#include <bits/stdc++.h>
#define ll long long
#define mod %
#define maxn 10000000
#define write cout <<
using namespace std;
ll a[maxn];
int Giang_Bae(ll n, ll k, ll s, ll c1, ll c2, ll m)
{
    a[1] = s;
    c1 = c1 mod m, c2 = c2 mod m;
    for (int i = 2; i <= n; i++)
    {
        a[i] = (c1 * (a[i - 1] mod m) mod m + c2) mod m;
        if (a[i] == 31882) cout<<i<<endl;
    }
    sort(a, a + n + 1);
    for (int i = 1; i <= k; i++)
        cout << a[i] << " ";
    //cout<< endl;
    write endl;
}
int main()
{
    int t;
    cin >> t;
    ll n, k, s, c1, c2, m;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> k >> s >> c1 >> c2 >> m;
        Giang_Bae(n, k, s, c1, c2, m);
    }
}