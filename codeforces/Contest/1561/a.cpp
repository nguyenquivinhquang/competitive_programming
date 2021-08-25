#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, a[N], b[N];
void solve() {
    cin >> n; 

    for (int i = 1; i <= n; i++) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    for (int i = 1; i <= n  *2; i++) {
        int s, e;
        bool check = true;
        for (int j = 1; j <= n; j++) check &= (a[j] == b[j]);
        if (check == true) {
            cout << i - 1<< "\n"; return;
        }
        if (i % 2 == 1) s = 1, e = 2; else s = 2, e = 1;
        for (int j = s; j <= n-e; j+=2) {
            if (a[j] > a[j + 1]) swap(a[j], a[j+1]);
        }
        
        
    }
    cout << n << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; cin >> testcase;
    while(testcase--) solve();
}
