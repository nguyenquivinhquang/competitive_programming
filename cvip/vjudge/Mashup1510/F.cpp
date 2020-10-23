#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int MaxN = 200000;
using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, l = 0, r = 0;
    char a[MaxN + 1];
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == '(') l++; else r++;
    }
    if (l != r) {
        cout << "No";
        return 0;
    }
    l = r = 0;
    for (int i = 1; i <= n; i++) {
        if (a[i] == '(') l++;
        else {
            if (l > 0) l--; else r++;
        }
    }
    if (abs(l) > 1) cout << "No";
    else cout << "Yes";

}