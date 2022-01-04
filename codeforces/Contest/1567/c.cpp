#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int dp[N], remain[3], a[30];
int add_num(int fi, int num) {
    int temp = num, len = 1;
    while (temp > 0) {
        temp /= 10;
        len *= 10;
    }
    return  fi * len + num;
}
void solve() {
    string str;
    memset(dp, 0, sizeof(dp));
    memset(remain, 0, sizeof(remain));
    cin >> str; reverse(str.begin(), str.end());
    vector<int> cur;
    for (int i = 0; i < str.length() + 3; i++) {
        vector<int> temp;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                int num = x + y + remain[i];
                if (num > 10) remain[i + 2]++, num /= 10;
                if (cur.size())
                for (auto v : cur) temp.push_back(add_num(num, v));
                else temp.push_back(num);
            }
        }
        cur = temp;
    }
    reverse(str.begin(), str.end());
    int res = 0;
    stringstream geek(str);
    geek >> res;
    ll total = 0;
    for (auto v : cur) if (v == res) total++;
    cout << total << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
    // cout <<add_num(3, 1);
}
