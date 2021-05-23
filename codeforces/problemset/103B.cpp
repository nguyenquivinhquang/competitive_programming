#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
vector<int> vertice[N];
int m, n;
bool fee[N], check = false;
void dfs(int u, int preU) {
    fee[u] = true;
    for (auto v : vertice[u]) {
        if (v == preU) continue;
        if (fee[v] == true) {
            continue;
        }
        dfs(v, u);
    }
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(fee, false, sizeof(fee));
    cin >> n >> m;
    int u, v;
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    dfs(1, - 1);
    int isConnect = 0;
    for (int i = 1; i <= n; i++)
        if (fee[i] == true) isConnect++;
    if (isConnect == n && n == m) cout << "FHTAGN!";
    else cout << "NO";

}
