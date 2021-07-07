#include <bits/stdc++.h>
#define pp pair<long long, long long>
#define ll long long
using namespace std;
const int N = 10000;
ll n, m ,t;
pp Time[N];
bool check() {
    ll capa = n, ss = 0;
    for (int i = 1; i <= m; i++) {
        capa -= (Time[i].first - ss);
//        cout << capa << endl;
        if (capa <= 0) return false;
        ss = Time[i].second;
        capa += (Time[i].second - Time[i].first);
        capa = min(capa, n);
    }
    capa -= (t - ss);
    return capa > 0;

}
signed main() {
    ios_base::sync_with_stdio(NULL), cin.tie(NULL);
    cin >> n >> m >> t;
    for (int i = 1; i <= m; i++)
        cin >> Time[i].first >> Time[i].second;
    if (check()) cout << "Yes"; else cout << "No";

}
