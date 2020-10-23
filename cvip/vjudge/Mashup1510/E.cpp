#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>


const int N = 1000002;
using namespace std;
vector<char> a[N];
vector<bool> fee[N];
int n, m;

bool dfs(int u, int v) {
    if (u == 0 || v == 0 || v > m || u > n)
        return false;
    if (a[u][v] == '#' || fee[u][v] == false)
        return false;
    if (u == n && v == m)
        return true;
    bool check = false;
    fee[u][v] = false;
    if (dfs(u + 1, v) || dfs(u, v + 1))
        check = true;
    return check;

}

void debug() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            cout << fee[i][j] << " ";
        cout << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    char temp;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        a[i].push_back('X');
        fee[i].push_back(true);
        for (int j = 1; j <= m; j++) {
            cin >> temp;
            a[i].push_back(temp);
            fee[i].push_back(true);
        }
    }
    //fee[1][1] = false;
    int res = 0;
    while (dfs(1, 1) == true) {
        res++;
        fee[1][1] = true;
    }
    cout << res;
}

/*
 * DON'T USE END
 *
 */