#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define pp pair<int, int>

const int N = 1009;
const int Mod = 998244353;
using namespace std;

int n, k;
map<int, int> trace;
int dp[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    int temp;
    for (int i = 1; i <= n; i++) {
        cin  >> temp;
        trace[temp]++;
    }
    int i = 1;

    dp[0] = 1;
    for (auto v : trace) {
        ll c = v.second;
        for (int j = k; j >= 1;j--) {
            dp[j] += dp[j-1] * c;       
            dp[j] %= Mod;
        }
    }
    cout << dp[k];
}
