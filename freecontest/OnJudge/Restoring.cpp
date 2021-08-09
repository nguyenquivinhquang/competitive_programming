#include <bits/stdc++.h>
#define ll long long
#define pp pair<long long, long long>
#define int long long
using namespace std;
const int N = 1000;
const int Inf = 1e15;
int n, d[N][N], a[N][N], parent[N], Rank[N];
ll res = 0;
vector<pair<int,pp>> edge;

void make_set() {
    for (int v = 1; v <= n; v++) {
        parent[v] = v;
        Rank[v] = 0;
    }
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b, int cost) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (Rank[a] < Rank[b])
            swap(a, b);
        parent[b] = a;
        if (Rank[a] == Rank[b])
            Rank[a]++;
        res += cost;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    for (int i = 1; i <= 300; i++)
        for (int j = 1; j <= 300; j++)
            d[i][j] = Inf;

    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            d[i][j] = a[i][j];

        }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n; j++)
            if ((d[i][j] !=  a[i][j] && i != j)) {
                cout << i << " " << j;
                return 0;
            } else edge.push_back({d[i][j], {i, j}});

    }
    make_set();
    sort(edge.begin(), edge.end());
    for (auto e : edge) {
        union_sets(e.second.second, e.second.first, e.first);
    }
//    for (int i = 1; i <= n; i++)
//        for (int j = 1; j <= i; j++)
//            if (find_set(i) != find_set(j)) {
//                cout <<-1;
//                return 0;
//            }
    cout << res;
}
