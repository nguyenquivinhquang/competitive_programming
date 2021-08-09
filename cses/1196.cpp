#include <bits/stdc++.h>
 
#define ll long long
#define pp pair<ll, ll>
 
const int N = 100009;
// #define int long long;
using namespace std;
int n, m, k;
vector<ll> d[N];
vector<pp> vertice[N];  //first : destination, second: cost
void shortest_path() {
    vector<int> vis(n+1);
    multiset<pp> q;
    q.insert({0, 1});
    while (q.size() != 0) {
        int u = q.begin()->second;
        ll w = q.begin()->first;
        q.erase(q.begin());
        
        if (vis[u] >= k) continue;
        vis[u]++;

        d[u].push_back(w);

        for (auto e : vertice[u]) {
            int v = e.first, len = e.second;
            // if (u == 8)
            //     cout << "hihi";
            if (vis[v] < k) q.insert({w + len, v});
        }
    }
    // for (auto v : d[7])
    //     cout << v << " ";
    // cout << endl;
    // for (auto v : d[8])
    //     cout << v << " ";
    // // cout << endl;
    // for (auto v : d[1])
    //     cout << v << " ";
    // cout << endl;
    // cout << "1" << endl;
    for (auto v : d[n]) {
        cout << v << " ";
    }
}
signed main() {
    //ios_base::sync_with_stdio(false), cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    int x, y, w;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        vertice[x].push_back({y, w});
    }
    shortest_path();
}
 
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!
 
 
*/
