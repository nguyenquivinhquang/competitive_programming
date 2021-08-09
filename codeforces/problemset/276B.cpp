#include <bits/stdc++.h>
#define maxn 200001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
ll n, m, a[maxn], fen[maxn], l, r, new_a[maxn];

void update(int pos, int val)
{
    for (int i = pos; i <= n; i += i & -i)
        fen[i] += val;
}
ll sum(int pos)
{
    ll ans = 0;
    for (int i = pos; i; i -= i & -i)
        ans += fen[i];
    return ans;
}
int main()
{
    cin >> n >> m;
    memset(fen, 0, sizeof(fen));
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= m; i++)
    {
        cin >> l >> r;
        update(l, 1);
        update(r + 1, -1);
    }
    for (int i = 1; i <= n; i++)
    {
        new_a[i] = sum(i);
    }
    sort(new_a + 1, new_a + 1 + n);
    ll res = 0;
    for (int i = 1; i <= n; i++)
        res += new_a[i] * a[i];
    cout << res;
}