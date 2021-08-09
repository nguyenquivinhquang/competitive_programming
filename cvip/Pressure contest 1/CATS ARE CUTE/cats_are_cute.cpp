#include <bits/stdc++.h>
#define ll long long
#define int ll
using namespace std;
int n, total_2 = 0, total_5 = 0;
ll num;
void solve() {
    cin >> n;
    for (int i =1 ; i <= n; i++) {
        cin >> num;
        while (num % 2 == 0 || num % 5 == 0) {
            if (num % 2 == 0) num /= 2, total_2++;
            if (num % 5 == 0) num /= 5, total_5++;
        }
    }
    cout << min(total_2, total_5);
}
signed main() {
    solve();
}

