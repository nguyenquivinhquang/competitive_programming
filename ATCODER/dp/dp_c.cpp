#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 100009;
int a[N], b[N], c[N], n;
signed main() {
    ios::sync_with_stdio(false), cin.tie(NULL);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        a[i] += max(b[i - 1], c[i -1]);
        b[i] += max(a[i - 1], c[i -1]);
        c[i] += max(b[i - 1], a[i -1]);
    }
    cout << max(max(a[n], b[n]), c[n]);
}
