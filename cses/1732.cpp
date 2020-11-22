//https://cses.fi/problemset/task/1732
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
vector<int> prefix_function(string &s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j]) j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string a;
    cin >> a;
    vector<int>  pi = prefix_function(a);
    vector<int> res;
    int cur = pi.back();
    while (cur != 0){
        res.push_back(cur);
        cur = pi[cur - 1];
    }
    reverse(res.begin(), res.end());
    for (auto v : res)
        cout << v << " ";


}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
