#include <bits/stdc++.h>
const int N = 200005;
using namespace std;
 
vector<int> dp(N, 1);
// vector<set<int>> amount(N);
set<int> amount[N];
vector<vector<int>> vec(N);
vector<int> color(N);
void add(set<int>& s1, set<int>& s2, int index) {
    if (s1.size() < s2.size()) swap(s1, s2);
    for (auto& i : s2) s1.insert(i);
    dp[index] = s1.size();
    s2.clear();
}
 
void DFS(int index, vector<vector<int>>& vec, vector<int>& color, int preId) {
    amount[index].insert(color[index]);
    for (auto i : vec[index]) {
    	if (i == preId) continue;
        DFS(i, vec, color, index);
        add(amount[index], amount[i], index);
    }
}
 
signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;

 
    for (int i = 1; i < n; ++i) {
        int u, v;
        cin >> u >> v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
	// cerr << "ok";
    for (int i = 1; i <= n; ++i) cin >> color[i];
 
    DFS(1, vec, color, 0);
    for (int i = 1; i <= n; ++i){ 
    	vec[i].clear();
    	cout << dp[i] << ' ';
    }
}