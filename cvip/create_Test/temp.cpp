#include <bits/stdc++.h>
using namespace std;

#define int long long

void print(vector<int> a) {
	int n = a.size();
	for (int i = 0; i < n; i++) {
		cout << a[i];
		if (i != n-1) cout << ' ';
	}
	cout << '\n'; exit(0);
}

void solve1(int n, vector<int> a) {
	//cerr << "Solving one\n";
	set<int> s;
	int lastpos = -1;
	int ascent;
	for (int i = n-1; i > 0; i--) {
		ascent = a[i-1] < a[i];

		//cerr << i << ' ' << ascent << '\n'; 
		//for (int j: s) cerr << j << ' '; cout << '\n';

		if (ascent) {
			// just find something larger than a[i]
			auto it = s.upper_bound(a[i]);
			if (it == s.end()) {
				s.insert(a[i]);
				continue;
			}

			lastpos = i; break;
		} else {
			// find something smaller than a[i-1], greater than a[i], must not already be greatest in set
			auto it = s.upper_bound(a[i]);
			if (it == s.end()) {
				s.insert(a[i]);
				continue;
			}
			it++;
			if (it == s.end()) {
				s.insert(a[i]);
				continue;
			}
			it--;
			if (*it >= a[i-1]) {
				s.insert(a[i]);
				continue;
			}

			lastpos = i; break;
		}
	}
	if (lastpos == -1) return;

	int lastval = a[lastpos];
	s.clear();
	while (a.size() > lastpos) {
		s.insert(a.back());
		a.pop_back();
	}

	if (!ascent) {
		// currently descent, insert nxt = upperbound(lastval), then nxt2 = upperbound(nxt)
		auto it = s.upper_bound(lastval);
		auto it2 = s.upper_bound(*it);

		a.push_back(*it); a.push_back(*it2);
		s.erase(it); s.erase(it2);
	} else {
		// currently ascent, just insert bigger than lastval
		auto it = s.upper_bound(lastval);

		a.push_back(*it);
		s.erase(it);
	}

	// keep constructing ascents
	vector<int> gg(s.begin(), s.end());
	int sss = gg.size();
	for (int i = 1; i+1 < sss; i += 2) {
		swap(gg[i], gg[i+1]);
	}
	for (int i: gg) a.push_back(i);
	print(a);
}

void solve2(int n, vector<int> a) {
	//cerr << "Solving two\n";
	// change first descend to first ascend
	if (a[0] == n) return;
	if (a[0] < a[1]) {
		return;
	}

	set<int> s;
	while (a.size() > 1) {
		s.insert(a.back());
		a.pop_back();
	}

	// first ascend
	auto it = s.upper_bound(a[0]);
	a.push_back(*it); s.erase(it);

	vector<int> gg(s.begin(), s.end());
	int sss = gg.size();
	for (int i = 1; i+1 < sss; i += 2) {
		swap(gg[i], gg[i+1]);
	}
	for (int i: gg) a.push_back(i);
	print(a);
}

void solve3(int n, vector<int> a) {
	//cerr << "Solving three\n";
	// change first element
	int firstval = a[0];
	if (firstval == n) return;

	set<int> s;
	while (a.size()) {
		s.insert(a.back());
		a.pop_back();
	}

	auto it = s.upper_bound(firstval);
	a.push_back(*it); s.erase(it);

	vector<int> gg(s.begin(), s.end());
	int sss = gg.size();
	for (int i = 1; i+1 < sss; i += 2) {
		swap(gg[i], gg[i+1]);
	}
	for (int i: gg) a.push_back(i);
	print(a);
}

void solve4(int n) {
	//cerr << "Solving four\n";

	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}

	vector<int> a;
	vector<int> gg(s.begin(), s.end());
	int sss = gg.size();
	for (int i = 1; i+1 < sss; i += 2) {
		swap(gg[i], gg[i+1]);
	}
	for (int i: gg) a.push_back(i);
	print(a);
}

signed main() {
	ios::sync_with_stdio(0); cin.tie(0);
	
	int n; cin >> n;
	if (n == 1) {
		cout << "1\n"; exit(0);
	}
	if (n == 2) {
		int x, y; cin >> x >> y;
		swap(x, y);
		cout << x << ' ' << y << '\n';
		exit(0);
	}
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	// change one suffix without changing order
	solve1(n, a);

	// change -1 suffix, change order
	solve2(n, a);

	// change everything
	solve3(n, a);

	// first perm
	solve4(n);

	return 0;
}
