#include <bits/stdc++.h>


using namespace std;

signed main() {
    ios_base::sync_with_stdio(NULL), cin.tie(NULL);
    int a[5], res = 101;
    for (int i = 1; i <= 4; i ++) {
        cin >> a[i];
        res = min(res, a[i]);
    }
    cout << res;

}
