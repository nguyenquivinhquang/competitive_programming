#include <bits/stdc++.h>
#define maxn 105
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("out.txt", "w", stdout)
using namespace std;
ll dp[maxn][maxn], a[maxn][maxn], area, res;
int n, m, K;
int main()
{
	//inputfile;
	//outputfile;
	int testcase = 0;
	cin >> testcase;
	for (int t = 1; t <= testcase; t++)
	{
		cin >> n >> m >> K;
		memset(dp, 0, sizeof(dp));
		res = 0, area = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
			{
				cin >> a[i][j];
				dp[i][j] = a[i][j] + dp[i - 1][j];
			}
		for (int x = 1; x <= n; x++)
			for (int i = 1; i <= n; i++)
			{
				ll total_cost = 0, l = 0, width = 0, height = (i - x + 1);
				for (int j = 1; j <= m; j++)
				{
					total_cost += (dp[i][j] - dp[x][j] + a[x][j]);

					if (total_cost > K)
					{
						while (total_cost > K && l < j)
						{
							l++, total_cost -= (dp[i][l] - dp[x][l] + a[x][l]);
						}
						if (total_cost < (dp[i][j] - dp[x][j] + a[x][j]))
							total_cost = (dp[i][j] - dp[x][j] + a[x][j]);
					}
					width = (j - l);
					if (total_cost <= K)
					{
						if (area == (width * height))
							res = min(res, total_cost);
						else if (area < width * height)
						{
							res = total_cost;
							area = width * height;
						}
					}
					else
						total_cost = 0;
				}
			}
		cout << "Case #" << t << ": " << area << " " << res << endl;
	}
}