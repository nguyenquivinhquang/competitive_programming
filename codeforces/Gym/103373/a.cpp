#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
struct infor {
        int g, s, b;
        string country;
};
bool cmp(infor x, infor y) {
    if (x.g == y.g) {
        if (x.s == y.s) {
            return x.b < y.b;
        }
        return x.s < y.s;
    }
    return x.g < y.g;
}
vector<infor> a;
int n;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        infor temp; cin >> temp.g >> temp.s >> temp.b;
        getline(cin, temp.country);
        a.push_back({temp});
    }
    sort(a.begin(), a.end(), cmp);
    reverse(a.begin(), a.end());
    string res = a[0].country;
    for (int i = 1; i < res.size(); i++) cout << res[i];
}
