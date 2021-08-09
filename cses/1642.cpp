#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1005;

using namespace std;

int n, x;
int a[N];
map<int, pp> trace;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> x;
    for (int i = 1; i <= n; i++) 
        cin >> a[i];
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <=n; j++)
            trace[a[i] + a[j]] = {i, j};
     for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <=n; j++) {
            int rem = x - a[i] - a[j];
            if (rem > 0 && trace.count(rem) && trace[rem].first > j) {
                cout << i << " " << j << " " << trace[rem].first << " " << trace[rem].second;
                return 0;
            }
        }
    cout << "IMPOSSIBLE";
}
