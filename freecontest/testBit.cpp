#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;
vector<int> ans;
int n;
void solve(int l, int r, int lv) {
    if (l == r) return;
    int mid = (l + r) >> 1;
    ans[mid] = lv;
    solve(l, mid, lv + 1);
    solve(mid + 1, r, lv + 1);
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    ans.resize(n);
    solve(0, n, 1);
    for (auto v : ans) 
        cout << v << " ";

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/