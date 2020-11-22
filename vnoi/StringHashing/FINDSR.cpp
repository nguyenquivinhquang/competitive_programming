//https://www.spoj.com/problems/FINDSR/
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1010009;
using namespace std;
//int pi[N + 10];
void prefix_function(string &s) {
    int n = (int)s.length();
    unordered_map<int, int> check;
    vector<int> pi(n + 1);
    pi[0] = 0;
    pi[n] = 1e9;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }

    int p = n - pi[n - 1];
    int q = n / p;
    if (q * p != n) q = 1;
    cout << q << "\n";
    return;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    //freopen("output.txt", "r", stdin);
    string t;
    while (1) {
        cin >> t;
        if (t == "*")
            break;
        prefix_function(t);
    }
}