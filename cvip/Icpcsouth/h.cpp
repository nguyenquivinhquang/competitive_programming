#include <bits/stdc++.h>
using namespace std;

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("out.txt", "w", stdout);
    map<int, int> ss;
    vector<int> dp(1001, 10000000);
    ss[0] = 0;
    for (int i = 1; i <= 100; i++)
    {
        vector<int> vals;
        for (int j = -1000; j <= 1000; j++)
        {
            if (ss.find(j) == ss.end())
                continue;
            vals.push_back(j);
        }

        map<int, int> gs;
        for (int j : vals)
        {
            if (gs.find(j - i) == gs.end())
                gs[j - i] = 100000;
            if (gs.find(j + i) == gs.end())
                gs[j + i] = 100000;

            gs[j - i] = min(gs[j - i], ss[j] + 1);
            gs[j + i] = min(gs[j + i], ss[j] + 1);
        }
        for (int j = 0; j <= 1000; j++)
        {
            if (gs.find(j) != gs.end())
                dp[j] = min(dp[j], gs[j]);
        }

        swap(gs, ss);
    }
    cout << dp[500] << endl;
    int res = 0;
    for (int i = 1; i <= 499; i++)
    {
        cout << dp[i] << " " << dp[500 - i] << endl;
        if (dp[i] + dp[500 - i] < dp[500])
            res = i;
    }
    cout << res << endl;
    return 0;
}
