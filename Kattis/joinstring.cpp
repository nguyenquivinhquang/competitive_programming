#include <bits/stdc++.h>
const int N = 100009;

using namespace std;

int n;

string temp;
signed main() {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<deque<int>> a(n+ 1);
    vector<char> str[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        for (auto s : temp)
            str[i].push_back(s);
        a[i].push_back(i);
    }
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        if (a[x].size() < a[y].size()) {
            for (auto v : a[x])
                a[y].push_front(v);
            swap(a[x], a[y]);
        } else {
            for (auto v : a[y])
                a[x].push_back(v);
        }
        a[y].clear();

    }

    for (int i = 1; i <= n; i++) {
        if (a[i].size() != 0) {
            for (auto u : a[i]) {
                for (auto s : str[u])
                    cout << s;
            }
            return 0;
        }
    }
}
