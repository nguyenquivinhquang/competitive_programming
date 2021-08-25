#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
string str;
void sub1() { // k == 1
    char c = str[0];
    for (auto v : str) cout << c;
    cout << "\n";
}
void sub2() {
    string res;
    for (auto v : str) res.push_back('9');
    for (char x = '0'; x <= '9'; x++ ) {
        for (char y = '0'; y <= '9'; y++) {
            bool useMin = false;
            string temp; char mi = x, ma = y;
            if (x == '2' && y == '1') {
                cout << "hhi";
            }
            for (auto c: str) {
                if (useMin == true) temp.push_back(mi);
                else {
                    if (c <= ma) temp.push_back(ma);
                    else {
                        temp.push_back(mi);
                        useMin = true;
                    }
                }
            }
            
            if (temp >= str) 
                res = min(res, temp);
        }
    }
    cout << res << "\n";

}
void solve() {
    int k; 
    cin >> str >> k;
    if (k == 1) sub1(); else sub2();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase; cin >> testcase;
    while (testcase--) solve();
}
