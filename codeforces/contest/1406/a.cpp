#include <bits/stdc++.h>
#define N 200
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
void solve()
{
    int n, x[N];
    vector<int> a, b;
    map<int, int> trace;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i];
        trace[x[i]]++;
    }
    for (auto v : trace)
    {
        if (v.second == 1)
            a.push_back(v.first);
        else
        {
            a.push_back(v.first);
            b.push_back(v.first);
        }
    }

    int u = 0, v = 0, c = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (a[c] == i)
            c++;
        else
        {
            u = i;
            break;
        }
        if (c == a.size())
        {
            u = i + 1;
            break;
        }
    }
    c = 0;
    for (int i = 0; i <= 100; i++)
    {
        if (b.size() == 0)
            break;
        if (b[c] == i)
            c++;
        else
        {
            u = v = i;
            break;
        }
        if (c == b.size())
        {
            v = i + 1;
            break;
        }
    }
    cout << u + v << endl;
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