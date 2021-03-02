#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>
#define int ll
const int N = 100009;
const int INF = -1e18;
using namespace std;

int n, m, k, sa, sb, salary[N], val[N];

vector<int> vertice[N];
ll dfs(int u) {
    if (val[u] > INF) return val[u];
    if (vertice[u].size() == 0 ) val[u] = 0;
    for (auto v : vertice[u]) {
        val[u] = max(val[u], salary[v] + dfs(v));
    }
    return val[u];
}
void reset() {
    for (int i = 1; i <= n; i++)
        val[i] = INF;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(salary, 0, sizeof(salary));
    int u, v;
    string command;
    
    cin >> n >> m >> k >> sa >> sb;
    
    for (int i = 1; i <= m; i++) {
        cin >> u >> v;
        vertice[u].push_back(v);

    }
    for (int i = 1; i <= n; i++) {
        cin >> command;
        if (command == "SALARY") {
            cin >> salary[i];
        } else if (command == "PROPERTY") cin >> u >> u;
        else { 
            cin >> u;
            salary[i] = -u;
        }
    }
    reset();
    cout << dfs(sa) << " ";
    reset();
    cout << dfs(sb);

}
