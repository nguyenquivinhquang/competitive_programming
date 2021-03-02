#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
string a;
void solve() {
    cin >> a;
    if (a.length() % 2 != 0 || a[0] == ')' || a[a.length() - 1]=='(')   
        cout << "NO"; else cout << "YES";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase-- ) {
        solve();
        cout << "\n";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/