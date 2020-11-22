#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
void solve() {
    int n;
    ll res = 0;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr.begin(), arr.end());
    int e = arr[n - 2];
    for (int i = 0; i < n - 1; i++) {
        res += abs(arr[i] - e);
    }
    if (res >= arr[n - 1])
        cout << res - arr[n - 1];
    else {
        int t = abs(res - arr[n - 1]);
        n--;
        cout <<  t % n;
    }
    cout << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        solve();
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/