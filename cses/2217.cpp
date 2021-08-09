#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, m, trace[N], a[N];
ll res = 0;
void check(int x, int oldInd) {
    if (oldInd > trace[x - 1]  ) res++;
    if (trace[x] > trace[x - 1]) res--;
    if (oldInd < trace[x + 1]) res++;
    if (trace[x] < trace[x + 1]) res--;

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    cin >> n  >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];    
        trace[a[i]] = i;
    }
    trace[0] = 1e7;
    trace[n + 1] = 1e7;
    for (int i = 1; i<= n; i++) {
        if (trace[a[i]] < trace[a[i] - 1]) res++;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        swap(a[x], a[y]);
        x = a[y], y = a[x];
        int oldX = trace[x], oldY = trace[y];
       
        check(x, oldX);
        check(y, oldY);
        swap(trace[x], trace[y]);
        cout << res << "\n";
    }
}
