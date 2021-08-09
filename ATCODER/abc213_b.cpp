#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

ll n, x, m = 0, idx = 1;
vector<pp> a;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        a.push_back({x, i});
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    cout << a[1].second;
}
