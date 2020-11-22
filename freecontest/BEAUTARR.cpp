#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000000;

using namespace std;

ll res = 0;
int a[N], l = 1, r, n;
unordered_map<int, int> trace;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    l = 1;
    // a[++n] = -1;
    for (int i = 1; i <= n; i++) {
        int x = a[i];
        trace[x]++;
        while (trace[x] > 2) {
            trace[a[l++]]--;
        }
        res += (i - l + 1);
    }
    cout << res;
}
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/