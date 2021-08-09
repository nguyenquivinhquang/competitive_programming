#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 3001;

using namespace std;
int n, value[N];
vector<int> vertice[N];
bool check(int u) {
    int le = 0, c = 0;
    if (value[u] % 2 == 0)
        c = 1;
    else
        le = 1;
    for (auto v : vertice[u]) {
        if (value[v] % 2 == 0)
            c++;
        else
            le++;
    }
    return le > 1 && c > 0;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int x, y;
    vector<int> res;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> value[i];
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        vertice[x].push_back(y);
        vertice[y].push_back(x);
    }
    for (int i = 1; i <= n; i++) {
        if (check(i))
            res.push_back(i);
    }
    if (res.size()) {
        for (auto v : res)
            cout << v << " ";
    } else
        cout << "-1";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/