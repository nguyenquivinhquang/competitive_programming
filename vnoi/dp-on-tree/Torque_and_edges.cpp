//https://www.codechef.com/problems/TRANDED?fbclid=IwAR1H6ExF_JhLai1_1ssrBOnyFyxRCxwahvT1bBEpK8hEr65bzCyapKYVNYA
#include <bits/stdc++.h>
#define N 100005
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
vector<int> edge[N];
ll n, vertice[N], res = 0;
ll count_sum(int u, int preu)
{
    ll sum = vertice[u], val;
    for (auto v : edge[u])
    {
        if (v == preu)
            continue;
        val = count_sum(v, u);
        if (val > 0)
            sum += val;
    }
    res = max(res, sum);
    return sum;
}
void solve()
{
    int x, y;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> vertice[i];
        edge[i].clear();
    }
    res = vertice[1];
    for (int i = 1; i < n; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    count_sum(1, 0);
    cout << res << endl;
}
int main()
{
    fastio;
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}