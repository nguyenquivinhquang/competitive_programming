#include <bits/stdc++.h>
#define maxn 500
using namespace std;
int n, a[maxn][maxn], sum[maxn];
int gbae()
{
    int res = -1e9;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            memset(sum, 0, sizeof(sum));
            for (int k = i + 1; k <= n + i; k++)
            {
                int tmp = 0;
                for (int s = j + 1; s <= n + j; s++)
                {
                    sum[s] += a[k][s];
                    tmp += sum[s];
                    res = max(tmp, res);
                }
            }
        }
    }
    return res;
}

int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                cin >> a[i][j];
                a[i + n][j] = a[i][j + n] = a[i + n][j + n] = a[i][j];
            }
        }
        int res = gbae();
        cout << res << endl;
    }
}