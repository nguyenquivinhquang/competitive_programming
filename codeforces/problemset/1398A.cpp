#include <bits/stdc++.h>
#define N 50005
#define ll long long
#define pp pair<ll, ll>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x) memset(x, 0, sizeof(x))
#define quyen_sort(x, size) sort(x + 1, x + 1 + size);
using namespace std;
void solve()
{
    pp a[N];
    int n, temp;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[i] = {temp, i};   
    }
    sort(a + 1, a + 1 + n);
    if (a[1].first + a[2].first <= a[n].first)
    {
        vector<ll> res = {a[1].second, a[2].second, a[n].second};
        for (auto v : res)
            cout << v << " ";
    }
    else
        cout << -1;
    cout << endl;
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