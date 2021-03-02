#include <bits/stdc++.h>


using namespace std;
int n;
vector<int> res, a;


void solve() {
    cin >> n;
    res.clear(); a.clear();
    int temp;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    sort(a.begin(), a.end());
    int ss = 0, ee = a.size() - 1;
    int t = 0;
    while (ss <= ee) {
        if (t % 2 == 0) res.push_back(a[ss++]); else res.push_back(a[ee--]);
        t++;
    }
    reverse(res.begin(), res.end());
    for (auto v : res)
        cout << v << " ";
    cout <<  "\n";
}

signed main() {
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }

}
