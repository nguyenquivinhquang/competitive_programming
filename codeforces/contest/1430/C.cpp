#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
multiset<int> a;
void solve()
{
    vector<pp> a;
    int n, cur;
    cin >> n;
    cur = n;
    for (int i = n - 1; i >= 1; i--)
    {
        a.push_back({cur, i});
        cur = (cur + 1 + i) / 2;
    }
    cout << cur << endl;
    for (auto v : a)
        cout << v.first << " " << v.second << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}