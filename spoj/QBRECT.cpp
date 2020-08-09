#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
int a[maxn][maxn], h[maxn][maxn], res = 0, n, m;
void debug()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << h[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    fastio;
    //cout <<"aa"<<endl;
    memset(h, 0, sizeof(h));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            h[i][j] = a[i][j] == 1 ? h[i - 1][j] + 1 : 0;
        }

    for (int i = 1; i <= n; i++)
    {
        deque<int> d;
        int l[maxn], r[maxn];
        memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r));
        d.push_back(0);
        for (int j = 1; j <= m; j++)
            if (h[i][j])
            {
                while (d.size() != 1 && h[i][d.back()] >= h[i][j])
                    d.pop_back();
                l[j] = d.back() + 1;
                d.push_back(j);
            }
            else
                d.clear(), d.push_back(j);
        d.clear(), d.push_back(m + 1);
        for (int j = m; j >= 1; j--)
            if (h[i][j])
            {
                while (d.size() != 1 && h[i][d.back()] >= h[i][j])
                    d.pop_back();
                r[j] = d.back() - 1;
                d.push_back(j);
            }
            else
                d.clear(), d.push_back(j);
        for (int j = 1; j <= m; j++)
        {
            res = max(res, (r[j] - l[j] + 1) * h[i][j]);

        }

    }
    cout << res << endl;
}