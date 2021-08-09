#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, a[N];
void solve() {
    cin >> n;
    vector<int> mi, pl;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 2; i <= n; i++) {
        int t = a[i] - a[i - 1];
        if (t >= 0) pl.push_back(t);
        else mi.push_back(t);   
    }
    sort(mi.begin(), mi.end());
    sort(pl.begin(), pl.end());
    bool check = false;
    cout << "de" << endl;
    for (int i = 1; i < mi.size(); i++)
        if (mi[i] != mi[i - 1]) check = true;
    for (int i = 1; i < mi.size(); i++)
        if (pl[i] != pl[i - 1]) check = true;
    if (check) {
        cout << -1 << "\n";
        return;
    }
    if (mi.size() == 0 || pl.size() == 0) {
        cout << 0 << "\n";
        return;
    }
    ll ss = 0;
    for (auto v : mi) {
        ss += v;
    }
    for (auto v : pl) {
        ss += v;
    }
    int x = a[2] - a[1];
    int k = 1;
    while (x + k * ss < 0 ) {
        k++;
    }
    cout << ss << " " << x + k * ss << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cout << "------------" << endl;
        solve();
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/