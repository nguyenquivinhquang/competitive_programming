#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
bool cmp(string &a, string &b) {
    int x, y;
    for (int i = 0; i < a.length(); i++) {
        x = a[i] - '0', y = b[i] - '0';
        if (x == y) continue;
        return x < y;
    }
    return true;
}
bool check(int x) {
    map<int, int> check;
    while (x > 0) {
        check[x % 10]++;
        x /= 10;
    }
    for (auto v : check)
        if (v.second > 1) return false;
    return true;
}
signed main() {
    // ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // string a[N];
    // int n, m, res = 0;
    // cin >> n >> m;
    // for (int i = 1; i <= n; i++)
    //     cin >> a[i];
    // for (int i = 0 ; i < m; i ++){
    //     for (int i = 1 )
    // }
    int c = 0;
    for (int i = 100; i < 999; i++)
        if (check(i)) {
            c++;
            cout << i << endl;
        }
    cout << c;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/