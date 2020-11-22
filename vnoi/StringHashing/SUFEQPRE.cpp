//https://www.spoj.com/problems/SUFEQPRE/
#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define int long long
#define pp pair<int, int>
const int p = 31;
const int N = 1000011;
const int m = 1e9 + 7;
int prefixHash[N], po[N];
void computeHash(string &s) {
    ll ps = 1;
    prefixHash[0] = 0;
    for (int i = 1; i < s.length(); i++) {
        prefixHash[i] = (prefixHash[i - 1] + (s[i] - 'a' + 1) * ps) % m;
        ps = (p * ps) % m;
    }
    po[0] = 1;
    for (int i = 1; i < s.size(); i++)
        po[i] = (po[i - 1] * p) % m;
}
int computeSuffix(int l, int r) {
    return (prefixHash[r] + m - prefixHash[l - 1]) % m;
}
void solve() {
    string s;
    cin >> s;
    s = '1' + s;
    computeHash(s);
    int res = 0, le = s.length() - 1;
    for (int i = 1; i < s.length() - 1; i++)
        if ((computeSuffix(1, i) * po[le - i]) % m == computeSuffix(le - i + 1, le)) {
            res++;
        }
    cout << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    for (int i = 1; i <= testcase; i++) {
        cout << "Case " << i << ": ";
        solve();
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/