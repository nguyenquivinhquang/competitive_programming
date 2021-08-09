#include <bits/stdc++.h>
#define ll long long
#define N 10050
using namespace std;
ll n, m, depth[N], l[N], dp[N], res;
int a[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
			depth[j] = (a[i][j] != a[i - 1][j] ? 1 : depth[j] + 1);
		int prevv = 1;
		vector<int> dq;
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] != a[i][j - 1])
			{
				prevv = j;
				dq.clear();
			}
			while (!dq.empty() && depth[j] <= depth[dq.back()])
				dq.pop_back();
			l[j] = dq.empty() ? prevv : dq.back() + 1;
			dq.push_back(j);
			dp[j] = (j - l[j] + 1ll) * depth[j];
			if (l[j] - 1 >= prevv)
				dp[j] += dp[l[j] - 1];
			res += dp[j];
		}
	}
	cout << res;
}