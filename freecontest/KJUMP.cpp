#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, a, b, c;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> c;
        cout << max(b - a, c - b) - 1 << "\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/