#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
vector<int> prefix_function(string &s){
    int n = s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++){
        int j = pi[i - 1];
        while (j > 0 && s[j] != s[i])
            j = pi[j - 1];
        if (s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string a;
    cin >> a;
    vector<int> pi = prefix_function(a), res;
    int cur = pi.back();
    while (cur != 0) {
        res.push_back(a.length() - cur);
        cur = pi[cur - 1];
    }
    //reverse(res.begin(), res.end());
    res.push_back(a.length());
    for (auto v : res)
        cout << v << " ";

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
