#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int long long
const int N = 200009;

using namespace std;

int a[N];
int n;
void solve() {
    cin >> n;
    int sum = 0;
    for (int i= 1; i <= n; i++){ 
        cin >> a[i];
        sum += a[i];
    }
    ll mid = sum / n, remain = sum % n;
    ll x = n - remain, y = remain;

    cout << x * y << "\n";
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) solve();
}
