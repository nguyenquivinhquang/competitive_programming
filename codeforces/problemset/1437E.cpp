//https://codeforces.com/contest/1437/problem/E
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100;

using namespace std;
int n, k, a[N], b[N], total = 1, it[N * 4 + 5];
void add(int node, int l, int r, int val, int pos) {
    if (pos < l || pos > r)
        return;
    if (pos == l) {
        it[node] += val;
        return;
    }
    int mid = (l + r) / 2;
    add(node * 2, l, mid, val, pos);
    add(node * 2 + 1, mid + 1, r, val, pos);
    it[node] = max(it[node * 2], it[node * 2 + 1]);
}
int itfind(int node, int l, int r, int u, int v) {
    if (r < u || l > v)
        return -1e9;
    if (u <= l && r <= v) {
        return it[node];
    }
    int mid = (l + r) / 2;
    return max(itfind(node * 2, l, mid, u, v), itfind(node * 2 + 1, mid + 1, r, u, v));
}
unordered_map<int, int> compress;
bool checkImpossible() {
    for (int i = 2; i <= k; i++) {
        //cout << a[b[i]] << " " << a[b[i - 1]];
        if (a[b[i]] - a[b[i - 1]] < b[i] - b[i - 1]) return true;
    }
    return false;
}
int coutnLis(int l, int r) {
    if (l > r)
        return 0;
    memset(it, 0, sizeof(it));
    vector<int> dp;
    int res = 0;
    for (int i = l; i < r; i++) {
        if (a[i] >= a[r] && a[i] < a[l - 1])
            continue;
        res = max(res, itfind(1, 1, total, 1, a[i]) + 1);
        add(1, 1, total, 1, a[i]);
    }
    return r - l - res;
}
signed main() {
    //ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n >> k;
    int temp[N];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        temp[i] = a[i] - i;
    }
    for (int i = 1; i <= k; i++)
        cin >> b[i];

    if (checkImpossible()) {
        cout << -1;
        exit(0);
    }
    sort(temp + 1, temp + 1 + n);
    for (int i = 1; i <= n; i++)
        if (compress[temp[i]] == 0)
            compress[temp[i]] = total++;
    for (int i = 1; i <= n; i++) {
        a[i] -= i;
        a[i] = compress[a[i]];
    }
    //cout << "debug \n";
    b[0] = 0;
    a[0] = 0;
    b[k + 1] = n + 1;
    a[n + 1] = 1e9;
    int res = 0;
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i <= k + 1; i++) {
        cout << coutnLis(b[i - 1] + 1, b[i]) << " ";
    }
    cout << res;
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/