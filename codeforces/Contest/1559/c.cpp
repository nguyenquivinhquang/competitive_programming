#include <bits/stdc++.h>
#define int ll
#define ll long long
#define pp pair<int, int>

const int N = 10005;

using namespace std;
int n, a[N];
void solve() {
    cin >> n;
    int temp = 0;
    n++;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    a[0] = -1;
    bool check = false; int pos = -1;
    for (int i = 1; i < n; i++) {
//        if (a[i] == 1 && a[i-1] == 0) check = true, pos = i;
        if (a[i] == 1 && a[i-1] == 0) check = true, pos = i - 1;
    }
    if (a[1] == 1) {
    	cout << n << " ";
    	for (int i = 1; i < n; i++) cout << i << " ";
    	cout << "\n";
    	return;
    }
    if (a[n-1] == 0) {
    	for (int i = 1; i < n; i++) cout << i << " ";
    	cout << n << "\n";
    	return;
    }
    if (a[n-1] == 0 && a[1] == 1) pos = n-1, check = true;
    if (check == false) {
        cout << "-1\n"; return;
    }
    // cout << "ok " << pos << endl;
    for (int i = 1; i < n; i++) {
        if (i == pos ) cout << i << " " << n << " ";
//        if (i == pos  && i != n-1) cout << i << " " << n;
		else cout << i << " ";
    }
    cout << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase;
    cin >> testcase;
    while (testcase--) solve();
}
