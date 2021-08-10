#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
ll a[maxn][maxn], dp[maxn][maxn], h[maxn][maxn], res = 0, m, n, column[maxn][maxn];
void debug()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << column[i][j] << " ";
        cout << endl;
    }
}
void create_debug()
{
    n = 1, m = 7;
    a[1][1] = a[1][2] = 1;
    a[1][6] = 1, a[1][7] = 1;
    for (int i = 3; i <= 5; i++)
        a[1][i] = 2;
    h[1][1] = 2, h[1][2] = 3, h[1][3] = 2, h[1][4] = 4;
    h[1][5] = 2, h[1][6] = 6, h[1][7] = 2;
}
int main()
{
    fastio;
    // freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            h[i][j] = a[i][j] == a[i - 1][j] ? h[i - 1][j] + 1 : 1;
        }
    //create_debug();
    ll l[maxn], cur_square = 0;
    for (int i = 1; i <= n; i++)
    {
        stack<int> st;
        ll cur_square = 0;
        a[i][0] = -1;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == a[i][j - 1])
            {
                l[j] = j;
                while (st.empty() != 1 && h[i][st.top()] >= h[i][j])
                {
                    l[j] = st.top();
                    st.pop();
                }
                st.push(j);
            }
            else
            {
                l[j] = j;
                cur_square = h[i][j];
                while (st.empty() != 1)
                    st.pop();
                st.push(j);
            }
        for (int j = 1; j <= m; j++)
        {
            if (i == 3 && j == 4)
                cout << "brreal";
            int k = l[j];
            //cout << k <<" ";
            dp[i][j] = h[i][j] * (j - k + 1);
            dp[i][j] += a[i][j] == a[i][k - 1] ? dp[i][k - 1] : 0;
            res += dp[i][j];
            column[i][j] = dp[i][j];
        }
        //cout << endl;
    }
    debug();
    cout << res;
}