#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    string a;
    vector<char> res;
    cin >> a;
    res.push_back(a[0]);
    for (int i = 1; i < a.length(); i++) {
        if (a[i] != a[i - 1])
            res.push_back(a[i]);
    }
    for (auto v : res)
        cout << v;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/