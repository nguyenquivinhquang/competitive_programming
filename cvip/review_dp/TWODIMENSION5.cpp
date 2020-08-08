//5. The Knight – 2
#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
ll n, m, dp[maxn][maxn];

ll find_way(int i, int j)
{
    if (i == n && j == m)
        return 1;
    if (i < 1 || j < 1 || i > n || j > m)
        return 0;
    if (dp[i][j])
        return dp[i][j];

    dp[i][j] = find_way(i - 1, j + 2) + find_way(i + 1, j + 2) + find_way(i + 2, j + 1) + find_way(i + 2, j - 1);

    return dp[i][j];
}

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n >> m;
    dp[n][m] = 1;
    cout << find_way(1, 1);
}