#include <bits/stdc++.h>
#define ll long long
#define int unsigned long long
using namespace std;
const int N = 1000009;
bool isPrime[N];
vector<int> prime;
int dp[1001][1001];
void eratos() {
    memset(isPrime, true, sizeof(isPrime));
    isPrime[1] = false;
    for (int i = 2; i <= N - 1; i++) {
        if (isPrime[i] == false) continue;
        for (int j = i + i; j <= N - 1; j += i)
            isPrime[j] = false;
    }
    for (int i = 2; i <= N - 1; i++)
        if (isPrime[i] == true) prime.push_back(i);
}
bool check(int x) {
    ll t = round(sqrt(x));
    if (t * t == x) return true;
    t = round(pow(x, 1.0 / 3.0));
    if (isPrime[t] == true && t * t * t == x)
        return true;
    return false;
}
signed main() {

    ios_base::sync_with_stdio(false), cin.tie(NULL);
//    freopen("E:\\cp1\\spoj\\input.txt", "r", stdin);
    eratos();
    int n;
    string s;
    getline(cin, s);
    vector<int> a, b;
    a.push_back(0), b.push_back(0);
    stringstream ss(s);
    for (ll x; ss >> x; )
        if (check(x) == true) a.push_back(x);
    s.clear();
    getline(cin, s);
    stringstream ss2(s);
    for (ll x; ss2 >> x; )
        if (check(x) == true) b.push_back(x);

    memset(dp, 0, sizeof(dp));
    int m = a.size()-1; n = b.size()-1;

    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++) {
            if (a[i] == b[j]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    cout << dp[m][n];
//    cout << prime[prime.size() - 1];
}
