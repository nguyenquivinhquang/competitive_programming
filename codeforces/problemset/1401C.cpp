#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    int n, temp, m = 1e9;
    vector<int> a, b;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a.push_back(temp);
        m = min(m, temp);
    }
    b = a;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i] && a[i] % m != 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
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