#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n, a[N], b[N];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> b[i];
    for (int i = n; i >= 0; i--) {
        int c = 0;
        for (int j = 1; j <= n; j++)
            if (a[j] <= i && i <= b[j]) c++;
        if (c == i) {
            cout << c;
            return 0;
        }
    }
    unordered_map<int, int> test;
    cout << -1;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/