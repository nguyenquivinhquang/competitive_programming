#include <bits/stdc++.h>

#define ll long long
#define pp pair<int, int>

const int N = 100009;

using namespace std;

signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    ll n, a[N], sum = 0, res = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	for (int i = 1; i <= n; i++) {
		sum -= a[i];
		res += sum * a[i];
	}
	cout << res;
	

 }

/*
 Don't use endl, use '\n'
 just use endl with interactive problems !!


*/
