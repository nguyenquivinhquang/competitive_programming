#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) {
        ll p;
        cin >> p;
        if (6 * p >  2*1000000000000000000) cout << -1;
        else  {
            cout << 6 * p << " 3\n" << p << " " << 2 * p << " " << 3*p<<'\n';

        }
    }
}
