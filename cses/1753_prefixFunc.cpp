//https://cses.fi/problemset/task/1753

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
string n, m;
int res, si;
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    cin >> m;
    si = m.length();
    n = m + '#' + n;
    vector<int> t = prefix_function(n);
    for (auto v : t)
        if (v == si) res++;

    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/