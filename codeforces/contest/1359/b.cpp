#include <bits/stdc++.h>
#define maxn 101
#define ll long long
#define pp pair<ll, ll>
using namespace std;

int testcase;
int n, m, cost[maxn][maxn * 10];
char a[maxn][maxn * 10];
int main()
{
    int x, y;
    cin >> testcase;
    while (testcase--)
    {
        ll totalcost = 0;
        memset(cost, 0, sizeof(cost));
        cin >> n >> m >> x >> y;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                cin >> a[i][j];
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
                if (a[i][j] == '.')
                {
                    if (a[i][j - 1] == '.')
                        cost[i][j] = min(cost[i][j - 2] + y, cost[i][j - 1] + x);
                    else
                        cost[i][j] = cost[i][j - 1] + x;
                }
                else
                    cost[i][j] = cost[i][j - 1];
            totalcost += cost[i][m];
        }
        cout << totalcost << endl;
    }
}