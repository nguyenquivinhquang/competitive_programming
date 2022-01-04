#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 100009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int n, a[N], check1[N], check2[N];
void solve() {
    int odd = 0, even = 0;
    queue<int> odd_pos, even_pos, temp1, temp2;
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] % 2 == 0) even++, a[i] = 0;
        else odd++, a[i] = 1;
        if (a[i] ==1) odd_pos.push(i);
        else even_pos.push(i);
        check1[i] = i % 2;
        check2[i] = (i + 1) % 2;
    }
    temp1 = odd_pos, temp2 = even_pos;
    if (abs(even - odd) > 1) {
        cout << -1;
        return;
    }
    int res = 1e18, total = 0, c = 0;
    for (int i = 1; i <= n; i++) {
        if (check1[i] == 1 && odd_pos.size()) {
            total += abs(i - odd_pos.front());
            odd_pos.pop();
        } else if (even_pos.size()){
            total += abs(i - even_pos.front());
            even_pos.pop();
        } 
        c += check1[i];
    }
    odd_pos = temp1; even_pos = temp2; 
    if (c == odd) res = total;
    c = 0; total = 0;
    for (int i = 1; i <= n; i++) {
        if (check2[i] == 1 && odd_pos.size()) {
            total += abs(i - odd_pos.front());
            odd_pos.pop();
        } else if (even_pos.size()){
            total += abs(i - even_pos.front());
            even_pos.pop();
        }
        c += check2[i];
    }
    if (c == odd) res = min(res, total);
    
    cout << res / 2;
    
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
        cout << "\n";
    }
}
