#include <bits/stdc++.h>

#define ll long long
#define pp pair<ll, ll>
#define int long long
const int N = 5000;
const int K = 5000;
using namespace std;
int n, k, dp[K][N], res[K];
vector<pp> value[K];
ll manDistance(pp x, pp y) {
    return abs(x.first - y.first) + abs(x.second - y.second);
}

signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    int temp;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++){
            cin >> temp;
            value[temp].push_back({i, j});
        }
    for (int i = 1; i <= k; i++){
        res[i] = 1e15;
        if (value[i].size() == 0){
            cout << -1;
            return  0;
        }
    }
    res[1] = 0;
    for (int val = 2; val <= k; val++){
        for (int i = 0; i < value[val].size(); i++){
            dp[val][i] = 1e15;
            for (int j = 0; j < value[val - 1].size(); j++){
                // cout << val << " " << i << " " << j << endl; 
                // if (val == 4)
                //     cout << "debug";
                dp[val][i] = min(dp[val][i], manDistance(value[val][i], value[val - 1][j]) + dp[val - 1][j] );
                res[val] = min(res[val], dp[val][i]);
            }
        }
    }
    cout << res[k];
}