#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
struct fi {
    int prof, cost, day;
} a[N];
bool cmp(fi x,  fi y) {
    if (x.day != y.day) return x.day < y.day;
    if (x.prof != y.prof) return x.prof < y.prof;
    return x.cost > y.cost;
}
map<int, int> trace;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, m; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        double x, y, day; cin >> x >> y; day = (y / x) + 1;
        a[i].prof = x; a[i].cost = y, a[i].day = day;
    }
    sort(a + 1, a + 1 + n, cmp);
    int cur_prof = 0, cur_day = a[1].day - 1, cost = 0, i = 1;
    while (cur_day * cur_prof - cost < m) {
        cur_day++;
        while (i <= n && a[i].day == cur_day) {
            cost += a[i].cost;
            cur_prof += a[i].prof;
            i++;
        }

        
    }
    cout << cur_day;
}