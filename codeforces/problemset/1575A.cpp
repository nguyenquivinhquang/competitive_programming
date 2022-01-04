#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<string, int> pii;
typedef vector<int> vi;
vector<pii> vec;
int n, m;
bool cmp(pii a, pii b) {
    for (int i = 0; i < m; i++) {
        if (a.first[i] == b.first[i]) continue;
        if (i % 2 == 0) return a.first[i] < b.first[i];
        else  return a.first[i] > b.first[i];
    }
    return true;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> m;
    for (int i = 1 ; i <= n; i++) {
        string temp; cin >> temp;
        vec.push_back({temp, i});
    }
    sort(vec.begin(), vec.end(), cmp);
    for (auto v: vec) cout << v.second << " ";
}
