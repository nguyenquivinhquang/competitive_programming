#include <bits/stdc++.h>
#define N 16601151
//#define N 100
#define ll long long
#define pp pair<int, int>
#define Quyen "cute"
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Quyen_reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
ll n, a, b, c;
int fee[N + 1], co[N + 1], pre[N + 1], total = 0, level[N + 1], t = 0;
bitset<N + 2> group;
typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod
{
    ull b, m;
    FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
    ull reduce(ull a)
    {
        ull q = (ull)((L(m) * a) >> 64), r = a - q * b;
        return r >= b ? r - b : r;
    }
} FM(2);
void dfs1(ll u)
{
    stack<int> q;
    while (Quyen == "cute")
    {
        //t++;
        q.push(u);
        fee[u] = 1;
        ll temp = FM.reduce(a * u * u + b * u + c);
        if (fee[v] == -1)
        {
            pre[v] = u;
            level[v] = level[u] + 1;
            u = v;
        }
        else
        {
            if (fee[v] == 1)
            {
                fee[u] = fee[v] = 2;
                //swap(u, v);
                int d = abs(level[u] - level[v]) + 1;
                group[u] = group[v] = true;
                co[u] = co[v] = d;
                while (u != v)
                {
                    u = pre[u];
                    group[u] = true;
                    co[u] = d;
                    // t++;
                }
            }
            fee[u] = fee[v] = 2;
            while (q.size() != 0)
            {
                //t++;
                u = q.top();
                fee[u] = 2;
                q.pop();
                if (group[u] == false)
                    co[u] = co[v] + 1;
                v = u;
            }
            return;
        }
    }
}
void dfs2(int u)
{
    fee[u] = 1;
    int v = (a * u * u + b * u + c) % n;
    if (group[v] == 0 && fee[v] == 2)
    {
        dfs2(v);
    }
    co[u] = co[v] + 1;
}
int main()
{
    int testcase;
    int res = 1;
    cin >> testcase;
    while (testcase--)
    {
        res = 1;
        cin >> a >> b >> c >> n;
        FM = FastMod(n);
        Quyen_reset(fee, -1);
        group.reset();
        for (int i = 0; i < n; i++)
        {
            if (fee[i] == -1)
            {
                level[i] = 1;
                dfs1(i);
            }
        }
        for (int i = 0; i < n; i++)
        {
            // if (group[i] == 0 && fee[i] == 2)
            //     dfs2(i);
            res = max(res, co[i]);
        }
        cout << res << endl;
    }
}