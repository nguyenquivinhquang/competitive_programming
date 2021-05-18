#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
int n, k;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    for (int x = 0 ; x <= n; x++) 
        for (int y = 0; y <= n && 3 * y <= k; y++)
            for (int i = 0; i <= n && 4 * i <= k; i++)
                for (int j = 0; j <= n && 5 * j <= k; j++) {
                    if (2 * x + 3 * y + 4 * i + 5 * j == k && x + y + i + j == n) {
                        cout << x;
                        exit(0);
                    }
                    if (x + y + i + j > n) break;
                }
}

