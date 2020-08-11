#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mes(a, b) memset((a), (b), sizeof((a)))
#define syio                          \
    std::ios::sync_with_stdio(false); \
    std::cin.tie(0);                  \
    std::cout.tie(0);
typedef __int64 ll;
typedef long double real;

const int oo = ~0u >> 2;
const double pi = acos(-1.0);
const double eps = 1e-8;
const int mxn = 100033; //
inline int read()
{
    int x = 0, f = 1;
    char c = getchar();
    while (!isdigit(c))
        f = c == '-' ? -1 : 1, c = getchar();
    while (isdigit(c))
        x = x * 10 + c - '0', c = getchar();
    return x * f;
}
int n, m;
struct node
{
    ll a, b;
} nd[mxn];
bool cmp(node x, node y)
{
    if (x.a == y.a)
        return x.b > y.b;
    return x.a > y.a;
}
ll sum[mxn], sa[mxn];
int main()
{
    syio;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; ++i)
            cin >> nd[i].a >> nd[i].b;
        sort(nd + 1, nd + m + 1, cmp);
        for (int i = 1; i <= m; ++i)
        {
            sum[i] = sum[i - 1] + nd[i].a;
            sa[i] = nd[i].a;
        }
        ll res = 0;
        for (int i = 1; i <= m; ++i)
        {
            int pos = lower_bound(sa + 1, sa + m + 1, nd[i].b, greater<int>()) - sa;
            pos--;
            if (pos > n)
                res = max(res, sum[n]);
            else if (pos < i)
                res = max(res, sum[pos] + nd[i].a + (n - pos - 1) * nd[i].b);
            else
                res = max(res, sum[pos] + (n - pos) * nd[i].b);
        }
        cout << res << endl;
    }
    return 0;
}