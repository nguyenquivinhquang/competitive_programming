#include <bits/stdc++.h>
#define ll long long
const int N = 10000;

using namespace std;
int fee[N], n, k;

signed main() {
    cin >> n >> k;
    memset(fee, 0, sizeof(fee));
    int temp, res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        fee[temp % k]++;
    }
    for (int i = 0; i < k; i++) {
        if (i == k - i || i == 0 ){
            if (fee[i] != 0) fee[i] = 1;
            continue;
        }
        if (fee[i] < fee[abs(k - i)]) fee[i] = 0; else fee[abs(k - i)] = 0 ;
    }
    for (int i = 0; i < k; i++)
        res += fee[i];
    if (res == 0) res = 1;
    cout << res;
}
