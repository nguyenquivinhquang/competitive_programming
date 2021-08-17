#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 300000;

using namespace std;

int n, a[N], res = 0, pos[N];
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    pos[0] = n + 1;
    for (int i =1 ; i <= n; i++) cin >> a[i], pos[a[i]] = i;   
    for (int i = 1; i <= n; i++) {
        if (pos[a[i] - 1] < i) continue;
        res++;
    }
    cout << res;
}
