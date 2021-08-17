#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
int n, dp1[maxn], dp2[maxn], res = 0;
vector<int> tree[maxn];
void dfs(int u, int preu) {
    dp1[u] = 0;
    int m1 = 0, m2 = 0;
    for (auto v : tree[u]) {
        if (preu == v)
            continue;
        dfs(v, u);
        dp1[u] = max(dp1[u], dp1[v] + 1); 
        res = max(res, m1 + dp1[v] + 1) ;
        m1 = max(m1, dp1[v] + 1);
    }
    // res = max(res, m1 + m2 + 1);
    // res = max(res, dp1[u]);
    
}
int main() {
    memset(dp1, 0, sizeof(dp1));
    int x, y;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    dfs(1, 0);
    cout << res;
}