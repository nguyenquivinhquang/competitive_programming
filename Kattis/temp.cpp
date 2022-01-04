#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void solve() {

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("demo.txt", "r", stdin);
    vector<string> a; string str;
    while (cin >> str) {
        a.push_back(str);
    }
    reverse(a.begin(), a.end());
    for (auto v : a) cout << v << " ";
}
