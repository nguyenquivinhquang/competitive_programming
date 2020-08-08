#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
ll n, m, a[maxn][maxn], length = 0, trace[10], res = 0;
bool fee[maxn][maxn];
ll compute_sum()
{
    ll sum = 0;
    for (int i = 1; i <= length; i++)
    {
        sum += trace[i];
        cout << trace[i] << " ";
    }
    cout << endl;
    res = max(res, sum);
}
void dfs()
{
    bool check = false;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (fee[i][j] == false)
            {
                fee[i][j] = true;
                int k = i + 1;
                ll temp = a[i][j];
                length++;
                for (k; k <= n; k++)
                    if (fee[k][j] == false)
                    {
                        check = true;
                        fee[k][j] = true;
                        temp = temp * 10 + a[k][j];
                        trace[length] = temp;
                        dfs();
                    }
                    else
                        break;
                for (int t = i + 1; t <= n; t++)
                    fee[t][j] = false;
                k = j + 1, temp = a[i][j];

                for (k; k <= n; k++)
                    if (fee[i][k] == false)
                    {
                        check = true;
                        fee[i][k] = true;
                        temp = temp * 10 + a[i][k];
                        trace[length] = temp;
                        dfs();
                    }
                    else
                        break;
                for (int t = j + 1; t <= n; t++)
                    fee[i][t] = false;
                fee[i][j] = false;
                length--;
            }
    if (check == false)
        compute_sum();
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    memset(fee, false, sizeof(fee));
    dfs();
    cout << res << endl;
}