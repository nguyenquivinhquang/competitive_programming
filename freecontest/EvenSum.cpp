#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll n, temp, sum = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> temp;
        if (i % 2 == 0) sum += temp;
    }
    cout << sum;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/