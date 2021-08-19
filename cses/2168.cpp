#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 210000;
 
 
bool cmp(pair<pii,int> x, pair<pii,int> y) {
    if (x.first.first == y.first.first) return x.first.second > y.first.second;
    return x.first.first < y.first.first;
}

vector<pair<pii,int>> segment;
int n;
multiset<int> r, l;
bool res_1[N], res_2[N];
 
signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin.exceptions(cin.failbit);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x,y;
        cin >> x >> y;
        segment.push_back({{x, y}, i});
        l.insert(y);
    }
    sort(segment.begin(), segment.end(), cmp);
    for (auto seg: segment) {
        int ri = seg.first.second, le = seg.first.first;
        l.erase(l.lower_bound(ri));
        auto it = l.upper_bound(ri);
        if (it != l.begin()) res_1[seg.second] = 1;
    }
    for (int i = 1; i <= n; i++) cout << res_1[i] << " ";
    
    for (auto seg: segment) {
        int ri = seg.first.second, le = seg.first.first;
        auto it = r.lower_bound(ri);
        if (it != r.end()) res_2[seg.second] = 1;
        r.insert(ri);
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) cout << res_2[i] << " ";
 }