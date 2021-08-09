#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int prices[] = {0,7,27,41, 49, 63, 78, 108};
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    ll sum = 0;
    for (auto v : a) {
        cin >> v;
        sum += prices[v];
    }
    if (sum >=120) sum -=50;
    else if (sum >= 89) sum -=30;
    else if (sum >= 69) sum -=15;
    cout << sum << "\n";  
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
