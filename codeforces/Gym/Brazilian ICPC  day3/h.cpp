#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

ll x, y, add_1 = 0;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> x >> y;
    string temp = to_string(y);
    while (temp.length() < 19) {
        ll num = stoll(temp);
        // if (num - x < 0) continue;
        if ((num-x) % 9 == 0 && (num - x >= 0)) {
            ll mul = (num-x) / 9;
            cout << "Stable\n";
            if (x == y) {
                cout <<0;
                return 0;
            }

            if (add_1 == 0) cout << 1; else cout << 2;
            cout <<"\n";
            if ( mul != 0) cout << "+ " << mul;
            if (add_1 != 0 ) cout << "\n- " << add_1;
            return 0 ;
        }
        add_1++;
        temp = '1' + temp;
    }
    cout << "Broken";
}
