
#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 1000;

using namespace std;

int a, b, c, n, r;

void solve1() {
	cin >> n >> a >> b >> c;
	int Min = min(a, min(b, c));
	int Max = max(a, max(b, c));
	if (r ==  1) cout << min(Max - Min, Max); else cout << max(Min, Max - Min);
	cout << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
	cin >> r >> testcase;
    while (testcase -- )
		solve1();

}

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
