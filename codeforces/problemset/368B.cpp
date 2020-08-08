#include <bits/stdc++.h>
#define maxn 100002
using namespace std;
int n, m, lim = 0, dp[maxn];
vector<int> temp, a;
map<int, int> trace;
int encode(int x)
{
    return lower_bound(temp.begin(), temp.end(), x) - temp.begin() + 1;
}
void compressed()
{
    sort(temp.begin(), temp.end());
    temp.resize(distance(temp.begin(), unique(temp.begin(), temp.end())));
    for (auto &c : a)
        c = encode(c), lim = max(lim, c);
}
int main()
{
    int t;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        a.push_back(t);
        temp.push_back(t);
    }
    compressed();
    memset(dp, 0, sizeof(dp));
    for (int i = n - 1; i >= 0; i--)
    {
        if (trace[a[i]] == 0)
        {
            trace[a[i]] = i;
            dp[i+1] = dp[i + 2] + 1;
        }
        else
            dp[i+1] = dp[i + 2];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t;
        cout << dp[t] << endl;
    }
}