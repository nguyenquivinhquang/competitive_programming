#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
ll n;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        cin >> n;
        cout << 4 * n / __gcd(4 * n, n + 1) + 1<< endl;
    }
}

