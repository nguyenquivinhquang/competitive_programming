// Jisoo so cute
#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define double long double
const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
string a;
map<char, int> trace;
string res1, mid;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> a;
    cerr << a;
    for (auto v : a) {
        trace[v]++;
    }
    for (auto v : trace) {
        for (int i = 0; i < v.second / 2; i++) res1.push_back(v.first);
        v.second = v.second % 2;
        if (v.second == 1) mid.push_back(v.first);
    }

    sort(mid.begin(), mid.end());
    int n = mid.length();
    for (int i = 0; i < n; i++) {
        mid[n - i - 1] = mid[i];
    }
//    cout << mid;
    cout << res1 << mid;
    reverse(res1.begin(), res1.end());
    cout << res1;
}
