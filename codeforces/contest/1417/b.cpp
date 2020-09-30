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
map<int, int> need;
ll n, d, x;
void solve()
{

    need.clear();
    cin >> n >> d;
    for (ll i = 0; i < n; i++)
    {
        ll x;
        cin >> x;
        if (!need[x])
        {
            need[x] = 1;
            cout << 0 << ' ';
            need[d - x] = 2;
            continue;
        }
        cout << need[x] - 1 << ' ';
        if (d - x == x)
        {
            need[x] = (need[x] == 1) ? 2 : 1;
        }
    }
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