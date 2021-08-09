#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
const int N = 1000;

using namespace std;


signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll n;
    cin >> n;
    ll res = n * ((n - 1) / 2);
    if (n % 3 == 0) {
        cout << res - 2 * (n / 3); // chon 2 dinh -> tam giac can/deu. So tg deu bi trung -> tru
    }
    else cout <<res;
}
