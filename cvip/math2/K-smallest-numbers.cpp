#include <bits/stdc++.h>
#define ll long long
#define mod %
#define maxn 10000001

using namespace std;
ll a[maxn];
int Giang_Bae(ll &n, ll &k, ll &s, ll &c1, ll &c2, ll &m)
{
    ll t;
    int j = 0;
    t = s;
    memset(a, 0, sizeof(a));
    a[t]++;
    for (int i = 2; i <= n; i++)
    {
        t = (c1 * (t mod m)mod m + c2) mod m;
        a[t]++;
    }

    int i = 0;
    while (k >= 0)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            cout << i << " ";
            k--;
            if (k == 0)
                break;
        }
        if (k==0) break;
        i++;
    }

    cout << endl;
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