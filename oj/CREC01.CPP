#include <bits/stdc++.h>
#define MAXN 1001
#define ll long long
using namespace std;
bool a[MAXN][MAXN];
ll dp[MAXN][MAXN], column[MAXN][MAXN], res = 0;
int n, m;
void debug()
{
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << column[i][j] << " ";
            res += column[i][j];
        }
        cout << endl;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    memset(dp, 0, sizeof(dp));
    char temp;
    memset(column, 0, sizeof(column));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> temp;
            a[i][j] = temp == '1' ? 1 : 0;
            dp[i][j] = a[i][j] == 1 ? dp[i - 1][j] + 1 : 0;
        }
    int l[MAXN], pos[MAXN];
    for (int i = 1; i <= n; i++)
    {
        stack<int> st;
        int cur_square = 0;
        for (int j = 1; j <= m; j++)
        {
            l[j] = j;
            while (st.empty() != 1 && dp[i][st.top()] >= dp[i][j])
                st.pop();
            l[j] = st.empty() ? 1 : st.top() + 1;
            st.push(j);
        }
        for (int j = 1; j <= m; j++)
            if (dp[i][j])
            {
                int k = l[j] - 1;
                column[i][j] = dp[i][j] * (j - k) + column[i][k];
                res += column[i][j];
            }
    }
    //debug();
    cout << res;
}