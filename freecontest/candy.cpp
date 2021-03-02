#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int n, m, v[N];
pp candy[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll even = 0, odd = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        if (i % 2 == 0)
            even += v[i];
        else
            odd += v[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> candy[i].first >> candy[i].second;
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
s