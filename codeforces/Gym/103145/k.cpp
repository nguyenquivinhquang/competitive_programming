#include <bits/stdc++.h>
#define int long long 
#define ll long long
#define pp pair<int, int>

const int N = 500009;

using namespace std;
int parent[N], n, m, child[N], q;
vector<pair<int, pp>> edge;
void make_set(int v) {
    parent[v] = v;
    child[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return find_set(parent[v]);
}

ll union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a == b) return 0;
    if(child[a] < child[b])   swap(a,b);
    parent[b] = a;
    ll total = child[a] * child[b];
    child[a] += child[b];
    return total;
}
bool cmp(pair<int, pp> u, pair<int, pp> v) {
    return u.first > v.first;
}

void solve() {
    int x, y, c;
    cin >> n >> m >> q;

    for (int i = 1; i <= n; i++) make_set(i);

    for (int i = 1; i<= m; i++) {
        cin >> x >> y >> c;
        edge.push_back({c, {x, y}});
    }
    sort(edge.begin(), edge.end(), cmp);
    map<int, long long> trace;
    ll cur = 0;
    for (auto e : edge) {
        cur += union_sets(e.second.first, e.second.second);
        trace[e.first] = cur;
    }
    while (q--) {
        int x;
        cin >> x;
        auto it = trace.lower_bound(x);
        if (it == trace.end()) cout << "0\n";
        else  cout << it->second << "\n";
    }
    edge.clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
