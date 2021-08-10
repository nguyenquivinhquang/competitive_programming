#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    fastio;
    ll n, a[maxn], b[maxn], s1 = 1, s2 = 1, res = 0;
    vector<int> trace;
    bool fee[2 * maxn];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    a[n + 1] = 1e10, b[n + 1] = 1e10;
    for (int i = 1; i <= 2 * n; i++)
    {
        if (a[s1] < b[s2])
        {
            trace.push_back(1);
            s1++;
        }
        else
        {
            trace.push_back(0);
            s2++;
        }
    }
    for (int i = 1; i < 2 * n; i++)
        if (trace[i] != trace[i - 1] && trace[i-1] != 3)
        {
            res++;
            trace[i] = 3;
        }
    cout << res;
}