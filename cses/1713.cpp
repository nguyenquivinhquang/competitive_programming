#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;

using namespace std;
int c[N + 5];

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= N; i++)
        for (int j = i; j <= N; j += i)
            c[j]++;
    int testcase, x;
    cin >> testcase;
    while (testcase--) {
        cin >> x;
        cout << c[x] << "\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/