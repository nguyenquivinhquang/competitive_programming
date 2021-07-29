#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

double k[N];
int n,s;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) cin >> k[i];
    sort(k + 1, k + 1 + n);
    double res = (k[n]/1000.0) * s;
    res += 0.99999999;
    int resu = res;
    cout << resu;
}
