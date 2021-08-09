#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 2000000;

using namespace std;

int n, a[N], it[N * 4 + 10];
vector<int> res;
void build(int id, int l, int r) {
    if (l > r) return;
    if (l == r) {
        it[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    it[id] = it[id * 2 + 1] + it[id * 2];
}
bool update(int id, int l, int r) {
    if (l > r) return false;
    if (l == r) {
        if (it[id] == 0) return false;
        res.push_back(l);
        it[id] -= a[l];
        a[l] = 0;
        return true;
    }
    int mid = (l + r) / 2;
    bool check = false;
    if (it[id * 2] == it[id * 2 + 1]) {
        check = update(id * 2, l, mid);
        if (check == false)
            check = update(id * 2 + 1, mid + 1, r);
    } else if (it[id * 2] > it[id * 2 + 1])
        check = update(id * 2, l, mid);
    else
        check = update(id * 2 + 1, mid + 1, r);
    it[id] = it[id * 2 + 1] + it[id * 2];
    return check;
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    n = pow(2, n);
    int c2 = 0;
    memset(it, 0, sizeof(it));
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] >= 3) {
            cout << 0;
            exit(0);
        }
        if (a[i] == 2) c2++;
    }
    if (c2 > 1) {
        cout << 0;
        exit(0);
    }
    build(1, 1, n);
    bool check = true;
    while (check) {
        check = update(1, 1, n);
    }
    cout << res.size() << endl;
    for (auto v : res) {
        cout << v << " ";
    }
}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/