#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 200009;

using namespace std;
int n, group[N], fee[N], vertice[N], total = 0, ss[N], level[N], pre[N];
void dfs(int u) {
    int v = vertice[u];
    fee[u] = 1;
    // cout << v << " ";
    if (fee[v] == 1) {
        fee[u] = 2;
        int si = abs(level[u] - level[v] + 1);
        ss[++total] = si;
        group[u] = group[v] = total;
        while (u != v) {
            group[u] = total;
            u = pre[u];
        }
        // cout << ss[1] << endl;
        return;
    }
    // if (ss[1] == 5)
    //     cout << "1" ;
    if (fee[v] == -1) {
        level[v] = level[u] + 1;
        pre[v] = u;
        dfs(v);
    }
    fee[u] = 2;
    if (group[u] == 0) {
        group[u] = ++total;
        ss[total] = ss[group[v]] + 1;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> vertice[i];
    memset(fee, -1, sizeof(fee));
    memset(ss, 0, sizeof(ss));
    memset(group, 0, sizeof(group));
    for (int i = 1; i <= n; i++)
        if (fee[i] == -1) {
            level[i] = 1;
            dfs(i);
        }
    for (int i = 1; i <= n; i++) {
        cout << ss[group[i]] << " ";
        // else
        //     cout << level[i] << " ";
        // // cout << ss[i] << " ";
    }
}

/*
5
4 4 5 3 2

*/