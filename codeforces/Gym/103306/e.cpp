#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 3000000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], Capa = 0;
string str;
void solve() {
    cin >> n >> str;
    for (auto v : str) {
        if (v == 'T' || v =='G' || v == 'M' ) {
            if (v == 'G') Capa *= 1024;
            else if (v == 'T') Capa *= 1048576;
            continue;
        }
        Capa = Capa * 10 + v -'0';
    }
    for (int i = 1; i <= n; i++) cin >> a[i];
    int res = n, sum = 0, pos = -1;
    queue<pii> q;
    int j = 1;
    for (j = 1; j <= n; j++) {
        if (sum + a[j] > Capa) break;
        sum += a[j];
        q.push({a[j], j});
        res = j;
    }
    for (int i = j; i <= n; i++) {
        q.push({a[i], i});
        sum += a[i];
        while (sum > Capa && q.size()) {
            sum -= q.front().first;
            q.pop();
        }
        while (q.size() > res) {
            sum -= q.front().first;
            q.pop();
        }
        int x = q.size();
        res = min(res, x);
        
    }
    sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i <= res){
            sum += a[i];
            continue;
        }
        if (a[i] + sum > Capa) {
            pos = i - res;
            break;
        }
        sum += a[i];
        sum -= a[i-res];

    }
    cout << res << " " << pos << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    solve();
}
