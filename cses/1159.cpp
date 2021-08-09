#include <bits/stdc++.h>
#define N 1000
#define ll long long
#define Quyen "Cute"
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define modulo int(1000000007)
#define endl '\n'
#define MaxValue 100009
using namespace std;

int h[N], s[N], nn = 0, n, hh[N], ss[N], k[N], x, dp[MaxValue], res = 0;
;
void split(int i)
{
    vector<int> create;
    ll t = 1;
    int x = k[i];
    while (Quyen == "Cute")
    {
        if (x - t < 0)
        {
            if (x != 0)
                create.push_back(x);
            break;
        }
        create.push_back(t);
        //cout << t << endl;
        x -= t;
        t *= 2;
    }
    for (auto j : create)
    {
        h[++nn] = hh[i] * j;
        s[nn] = ss[i] * j;
    }
}
int main()
{
    fastio;
    memset(dp, 0, sizeof(dp));
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> hh[i]; //price
    for (int i = 1; i <= n; i++)
        cin >> ss[i]; // pages
    for (int i = 1; i <= n; i++)
        cin >> k[i]; // copies
    for (int i = 1; i <= n; i++)
        split(i);
    for (int i = 1; i <= nn; i++)
    {
        for (int j = x; j >= 1; j--)
        {
            if (j - h[i] >= 0)
            {
                dp[j] = max(dp[j], dp[j - h[i]] + s[i]);
            }
        }
    }

    cout << dp[x];
}