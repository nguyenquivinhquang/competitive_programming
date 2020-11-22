//https://cses.fi/problemset/task/1110
#include <bits/stdc++.h>
 
#define ll long long
#define pp pair<int, int>
 
const int N = 1000;
 
using namespace std;
int sort_cyclic_shifts(string & s) {
    int n = s.size();
    ///cout << "Hi";
    const int alphabet = 26;
    vector<int> p(n), c(n), cnt(max(alphabet, n), 0);
    for (int i = 0; i < n; i++)
        cnt[s[i] - 'a']++;
    for (int i = 1; i < alphabet; i++)
        cnt[i] += cnt[i-1];
    for (int i = 0; i < n; i++)
        p[--cnt[s[i] - 'a']] = i;
    c[p[0]] = 0;
    int classes = 1;
    for (int i = 1; i < n; i++) {
        if (s[p[i]] != s[p[i-1]])
            classes++;
        c[p[i]] = classes - 1;
    }
    vector<int> pn(n), cn(n);
    for (int h = 0; (1 << h) < n; ++h) {
        for (int i = 0; i < n; i++) {
            pn[i] = p[i] - (1 << h);
            if (pn[i] < 0)
                pn[i] += n;
        }
        fill(cnt.begin(), cnt.begin() + classes, 0);
        for (int i = 0; i < n; i++)
            cnt[c[pn[i]]]++;
        for (int i = 1; i < classes; i++)
            cnt[i] += cnt[i-1];
        for (int i = n-1; i >= 0; i--)
            p[--cnt[c[pn[i]]]] = pn[i];
        cn[p[0]] = 0;
        classes = 1;
        for (int i = 1; i < n; i++) {
            pair<int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
            pair<int, int> prev = {c[p[i-1]], c[(p[i-1] + (1 << h)) % n]};
            if (cur != prev)
                ++classes;
            cn[p[i]] = classes - 1;
        }
        c.swap(cn);
    }
    return p[0];
 
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    //freopen("input.txt", "r", stdin);
    string a;
    cin >> a;
    int pos = sort_cyclic_shifts(a);
 
    for (int i = pos; i < a.length(); i++)
        cout << a[i];
    for (int i = 0; i < pos; i++)
        cout << a[i];
}
 
/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!
 
 
*/