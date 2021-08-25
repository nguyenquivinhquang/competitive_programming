#include <bits/stdc++.h>
#define int long long
#define ll long long
#define pp pair<int, int>
 
const int N = 100009;
 
using namespace std;
pp a[N];
int n;
// bool cmp(pp x, pp y) {
//     if (x.first - x.second == y.first - y.second) return x.second < y.second;
//     return x.first - x.second < y.first - y.second;
// }
void solve() {
    cin >> n;
    for (int i =1 ; i <= n; i++) {
        int m, temp, Max = 0; cin >> m; 
        for (int i = 0; i < m; i++) {
            cin >> temp; temp -= i;
            Max = max(Max, temp + 1);
        }
        a[i].first = Max, a[i].second = m;
    }
    
    sort(a + 1, a + 1 + n);
    int init_cost = 0, cur_cost = 0;
    for (int i = 1; i <= n; i++) {
        int temp = 0;
        if (cur_cost < a[i].first) temp += a[i].first - cur_cost;
        cur_cost += a[i].second + temp ;
        init_cost += temp;
    }
    cout << init_cost << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase; cin >> testcase;
    while(testcase--) solve();
}