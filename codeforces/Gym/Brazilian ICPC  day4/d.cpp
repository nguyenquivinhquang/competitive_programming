#include <bits/stdc++.h>
 
#define ll long long
#define pp pair<int, int>
 
const int N = 300000;
 
using namespace std;
 
int interval[N], a[N];
// pp trace[N];
vector<pp> res[N];
map<int, pp> trace;
int n, m;
 
void cannot() {
    cout << "No";
    exit(0);
}
void add_value(int cur) {
	// for (auto v : trace) {
	// 	res[v.first].push_back(v.second);
	// }

	res[cur].push_back(trace[cur]);
	trace[cur].first = trace[cur].second = 0;
	// trace.clear();
}
signed main() {
	ios_base::sync_with_stdio(false), cin.tie(NULL);
	cin >> n;
	int pre = 0;
	for (int i = 1; i < n; i++){
		int temp;
		cin >> temp;
		m = max(m, temp);
		if (temp > min(i, n-i)*2) cannot();
		if (temp < pre) {
			add_value(pre);
		}
		if (trace[temp].first == 0) trace[temp].first = i;
		trace[temp].second = i + 1;
		if (temp % 2 == 1) cannot();
		pre = temp;
		
	} 
	for (auto v : trace) {
		if (v.first != 0) {
			res[v.first].push_back(v.second);
		}
	}
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 0; i <= m; i+= 2) {
		for (auto v : res[i]) {
			int x = v.first, y = v.second;
			swap(a[x], a[y]);
		}
	}
	cout << "Yes\n";
	for (int i = 1; i <= n; i++) cout << a[i] << " ";
 
}