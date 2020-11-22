//https://codeforces.com/contest/126/problem/B

#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000009;
const int p = 31;
const int m = 1e9 + 7;
using namespace std;

int n;
string s;

ll p_pow[N], h[N + 1];

void preProcess(string const& s) {
    p_pow[0] = 1;
    h[0] = 0;
    n = s.size();
    for (int i = 1; i <= n; i++)
        p_pow[i] = (p_pow[i - 1] * p) % m;

    for (int i = 1; i < n; i++)
        h[i] = (h[i - 1] + (s[i] - 'a' + 1) * p_pow[i]) % m;
}
bool countHash(int i, int l) {
    ll cur_h = (h[l] + m - h[0]) % m;
    cur_h = (cur_h * p_pow[i - 1]) % m;
    ll le = (h[i + l - 1] + m - h[i - 1]) % m;
    return cur_h == le;
}
int computeSuffix(int l, int r) {
    return (h[r] + m - h[l - 1]) % m;
}
ll check(int i) {
    int l = 1, r = n - i - 1, res = -1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (countHash(i, mid)) {
            res = mid;
            l = mid + 1;
        } else
            r = mid - 1;
    }
    if (res == -1) return -1;
    
    return res;
}

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> s;
    s = '#' + s;
    n = s.length() - 1;
    preProcess(s);
    pp res = {-1, -1};  //first position, sec: length
    // for (int i = 1; i < n; i++)
    //     cout << h[i] << " ";
    // cout << endl;
    for (int i = 2; i < n; i++) {
        ll t = check(i);
        if (res.second < t) {
            res = {i, t};
        }
    }
    int ma = res.second, le = -1;
    // cout << ma << endl;
    n = s.length() - 1;
    for (int i = 1; i < s.length() - 1; i++)
        if ((computeSuffix(1, i) * p_pow[n - i]) % m == computeSuffix(n - i + 1, n) && i <= ma) {
            le = i;
        }

    int ss = 1;
    // cout << le << endl;
    if (le != -1)
        while (le-- > 0) {
            cout << s[ss++];
        }
    else
        cout << "Just a legend";
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/