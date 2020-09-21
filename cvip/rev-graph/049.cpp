#include <bits/stdc++.h>
const int N = 1<<24;
//#define N 1000
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define Quyen_set(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
int co[N + 1], pre[N + 1], level[N + 1];
ll a, b, c, n;
short fee[N + 1];
bool group[N + 1];

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull reduce(ull a) {
		ull q = (ull)((L(m) * a) >> 64), r = a - q * b;
		return r >= b ? r - b : r;
	}
}FM(2);

void dfs1(int u)
{
    //cout << u << endl;
    ll temp = FM.reduce(a * u * u + b * u + c);
    int v = temp;
    fee[u] = 1;
    if (fee[v] == 1)
    {
        fee[u] = 2;
        swap(u, v);
        int d = abs(level[u] - level[v]) + 1;
        group[u] = group[v] = true;
        co[u] = co[v] = d;
        while (u != v)
        {
            v = pre[v];
            group[v] = true;
            co[v] = d;
        }
        return;
    }
    if (fee[v] == -1)
    {
        level[v] = level[u] + 1;
        pre[v] = u;
        dfs1(v);
    }
    fee[u] = 2;
    if (group[u] == false)
        co[u] = co[v] + 1;
}
int main()
{
    //output_file;
    //fastio;
    int testcase, res = 1;
    cin >> testcase;
    while (testcase--)
    {
        Quyen_set(group, false);
        res = 1;
        cin >> a >> b >> c >> n;
        FM = FastMod(n);
        //vector<bool> group(n + 1, false);
        Quyen_set(fee, -1);

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
            res = max(res, co[i]);
        }
        cout << res << endl;
    }
}