#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
const int N = 300000;
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N];
double k;
ll sum = 0;
bool is_integer(double k) {
    int t = floor(k);
  return t == k;
}
bool check(ll x, double k) {
 
}
void solve() {
    map<int,int> trace;
    ll res = 0;
    sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        trace[a[i]]++;
    }
    k = sum / (double) n;
 
    for (int i = 1; i <= n; i++) {
        ll s = sum - a[i];
        ll temp = k * (n - 2);
        // check stup
 
        double t = temp;
        t = t / (n-2);
        if (abs(t-k) > 1e-3) continue;
        ////
 
 
        int rem = s - temp;
        if (rem < 0 || trace[rem] == 0) continue;
 
 
        if (rem == a[i]) res += trace[rem]-1;
        else res += trace[rem];
//        cerr << a[i] << " " << trace[rem] << " " << rem << "\n";
    }
    cout << res/2 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}