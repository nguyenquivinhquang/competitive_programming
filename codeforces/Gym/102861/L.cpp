#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, 1, 1};
vector<int> dy = {0, 1, 1, -1};

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i];
	}

	vector<string> dic;
	vector<vector<pair<int, int>>> pss;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < 4; k++) {
				string str;
				vector<pair<int, int>> pos;

				str.push_back(s[i][j]);
				pos.emplace_back(i, j);

				for (int x = i + dx[k], y = j + dy[k]; x < n && y < m && y >= 0; x += dx[k], y += dy[k]) {
					str.push_back(s[x][y]);
					pos.emplace_back(x, y);

					if (str.size() >= 2 && str.size() <= 15) {
						sort(str.begin(), str.end());
						dic.push_back(str);
						pss.push_back(pos);
					}
				}
			}
		}
	}

	int cnt[n][m];
	memset(cnt, 0, sizeof(cnt));

	int q; cin >> q;
	while (q--) {
		string que; cin >> que;
		sort(que.begin(), que.end());

		set<pair<int, int>> xt;
		for (int i = 0; i < dic.size(); i++) {
			if (que == dic[i]) {
				for (auto [x, y]: pss[i]) {
					xt.insert({x, y});
				}
			}
		}
		for (auto [x, y]: xt) cnt[x][y]++;
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += (cnt[i][j] >= 2);
		}
	}
	cout << ans << '\n';

	return 0;
}