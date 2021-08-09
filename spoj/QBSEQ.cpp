#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long

const int N = 141;
const ll  inF = 1e9;
using namespace std;
int n, k, a[1009], temp;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int temp;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        a[i] = temp % k;
    }
    vector<int> f(k + 1, -inF), g(k + 1);
    f[0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            g[j] = max(f[j], f[(j - a[i] + k) % k]  + 1 );
        }

        f = g;
    }
    cout << g[0];

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
