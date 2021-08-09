#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;
int res[N];
void solve(int l, int r, int level) {
    if (l == r){ 
        // res[l] = level;
        return;
    }
    int mid = (l + r) / 2;
    res[mid] = level;
    solve(l, mid, level + 1);
    solve(mid + 1, r, level + 1);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int n, total = 21;
    cin >> n;
    solve(0, n, 1);
    for (int i = 0; i < n; i++)
        cout << res[i] << " ";
}
