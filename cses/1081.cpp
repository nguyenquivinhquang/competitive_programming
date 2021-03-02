#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;

using namespace std;
int fee[N + 3];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, x, res = 1;
    memset(fee, 0, sizeof(fee));
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        fee[x]++;
    }
    for (int i = 2; i <= N; i++) {
        int total = 0;
        for (int j = i; j <= N; j += i)
            total += fee[j];
        if (total > 1) res = max(res, i);
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/