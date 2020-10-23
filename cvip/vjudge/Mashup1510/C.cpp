#include <bits/stdc++.h>

#define int long long
#define pp pair<int, int>

const int N = 1000005;
using namespace std;
int n, m, a[N], b[N], p;
signed main()
{
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x1, x2;
    x1 = x2 = -1;
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        if (a[i] % p !=0 && x1 == -1)
            x1 = i;
    }
    for (int i = 1; i <= m; i++){
        cin >> b[i];
        if (b[i] % p !=0 && x2 == -1)
            x2 = i;
    }
    cout << x1 + x2 - 2;
}