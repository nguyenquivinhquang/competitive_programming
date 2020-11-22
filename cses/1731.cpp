//https://cses.fi/problemset/task/1731
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
 
#define ll long long
#define pp pair<int, int>
using namespace std;
 
const int N = 6000;
const int mod = 1e9 + 7;
const long long P = 53;
 
ll Pow[N];
int query, n, len[1000009];
string s, cur;
ll dp[N];
// unordered_map<ll, int> dic;
vector<ll> dic[1000009];
ll hashing(string &str) {
    ll hash = 0;
    for (int i = 0; i < str.length(); i++)
        hash = (hash + (str[i] - 'a' + 1) * Pow[i]) % mod;
    return hash;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    memset(len, 0, sizeof(len));
    cin >> s;
 
    Pow[0] = 1;
    for (int i = 1; i < s.length() + 2; i++)
        Pow[i] = (Pow[i - 1] * P) % mod;
 
    cin >> query;
    for (int i = 1; i <= query; i++) {
        cin >> cur;
        len[cur.length()] = 1;
        dic[cur.length()].push_back(hashing(cur));
    }
    for (int i = 0; i < 1000009; i++) {
        if (dic[i].size() != 0)
            sort(dic[i].begin(), dic[i].end());
    }
    n = s.length() - 1;
    dp[n + 1] = 1;
    for (int i = n; i >= 0; i--) {
        dp[i] = 0;
        ll hash = 0;
        for (int j = i; j <= n; j++) {
            hash = (hash + (s[j] - 'a' + 1) * Pow[j - i]) % mod;
            if (len[j - i + 1] != 1) continue;
            int si = j - i + 1;
            auto it = lower_bound(dic[si].begin(), dic[si].end(), hash);
            int t = 1;
            if (it == dic[si].end() || *it != hash) t = 0;
            dp[i] = (dp[i] + t * dp[j + 1]) % mod;
        }
    }
    cout << dp[0];
}