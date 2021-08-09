#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 1000;

using namespace std;

void solve() {
    string str;
    int a, b, n, res;
    cin >> n >> a >> b >> str;
    res = (a + b) * n;
    int len = 0;
    ll sum1 = 0, sum2= 0;

    str = str + 'C';
    vector<int> sub_1, sub_0;

    for (auto v : str) {
        if (v == '1') len++;
        else {
            if (len == 0 ) continue;
            sub_1.push_back(len);
            len = 0;
        }
    }
    len = 0;
    for (auto v : str) {
        if (v == '0') len++;
        else {
            if (len == 0 ) continue;
            sub_0.push_back(len); len = 0;

        }
    }
    sum1 = (min(sub_0.size(), sub_1.size()) + 1) * b + a * n;
    sum1 = max(sum1, res);

    cout << sum1 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) solve();
}
