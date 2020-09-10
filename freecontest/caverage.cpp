#include <bits/stdc++.h>
#define N 55
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int main()
{

    ll n, A, a[N], count = 0;
    vector<int> dp[N];
    map<int, ll> d[2500];
    cin >> n >> A;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[0].push_back(0);
    d[0][0] = 1;
    // for (int i = 1; i <= n; i++)
    //     for (int j = 100; j >= 1; j--)
    //     {
    //         if (j - a[i] < 0)
    //             continue;
    //         for (auto v : dp[j - a[i]])
    //         {
    //             if ((j)-A * (v + 1) == 0)
    //                 count++;
    //             dp[j].push_back(v + 1);
    //         }
    //     }

    for (int i = 1; i <= n; i++)
        for (int j = 2500; j >= 1; j--)
        {
            if (j - a[i] < 0)
                continue;
            for (auto v : d[j - a[i]])
            {
                if ((j)-A * (v.first + 1) == 0)
                    count += v.second;
                // dp[j].push_back(v + 1);
                d[j][v.first + 1] += v.second;
            }
        }
    cout << count;
}