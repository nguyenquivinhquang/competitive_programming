#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
void solve() {
    int res = 0, t1 = 0, t2 = 0;
    string a;
    cin >> a;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] == '(') t1++;
        if (a[i] == '[') t2++;
        if (a[i] == ')') {
            t1--;
            if (t1 >= 0) res++; else t1 = 0;
        }
        if (a[i] == ']') {
            t2--;
            if (t2 >= 0) res++; else t2 = 0;
        }
    }
    cout << res << "\n";
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin  >> testcase;
    while (testcase--) {
        solve();
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/