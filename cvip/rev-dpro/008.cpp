#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define Quyen "Cute"
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(a, val) memset(a, val, sizeof(a));
#define MaxValue 100005
#define endl '\n'

using namespace std;
int n, s[N], p[N], dp[MaxValue], m, nn, temp[MaxValue];
void split(int items, int price)
{
    vector<int> create;
    ll t = 1;
    nn = 0;
    while (Quyen == "Cute")
    {
        if (items - t < 0)
        {
            if (items != 0)
                create.push_back(items);
            break;
        }
        create.push_back(t);
        //cout << t << endl;
        items -= t;
        t *= 2;
    }
    for (auto j : create)
    {
        p[++nn] = price * j;
        s[nn] = j;
    }
}
void solve()
{
    int items, price, o;
    reset(dp, -1);

    reset(temp, 0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
        dp[i] = 1e9;
    while (n--)
    {
        cin >> items >> price >> o;
        split(items, price);
        for (int i = 1; i <= m; i++)
            temp[i] = dp[i] + o;
        temp[0] = o;
        for (int i = 1; i <= nn; i++)
        {
            for (int j = m; j >= 1; j--)
            {
                if (j - s[i] >= 0)
                {
                    temp[j] = min(temp[j], temp[j - s[i]] + p[i]);
                }
            }
        }
        for (int i = 1; i <= m; i++)
        {
            if (dp[i] != -1)
                dp[i] = min(dp[i], temp[i]);
            else
                dp[i] = temp[i];
        }
    }
    cout << dp[m] << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}