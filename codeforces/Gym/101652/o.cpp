#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 50;
int a[N][N];
int n;
int getVal(char x) {
    if (x - '0' >= 0 && x - '0' <= 9) return x - '0';
    else return x - 'A' + 10;
}
bool checkRow(int j) {
    map<int,int> trace;
    for (int i = 1; i <= n; i++) {
        trace[a[i][j]]++;
        if (trace[a[i][j]] > 1) return false;
    }
    return true;
}
bool checkCol(int i) {
    map<int,int> trace;
    for (int j = 1; j <= n; j++) {
        trace[a[i][j]]++;
        if (trace[a[i][j]] > 1) return false;
    }
    return true;
}
void solve() {
	for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            char x; cin >> x;
            a[i][j] = getVal(x);
        }
	}
	bool check = true;
	for (int i = 1; i <= n; i++) {
        check &= checkRow(i);
        check &= checkCol(i);
	}
	if (check == false) {
        cout << "No";
        return;
	}
    for (int i = 2; i <= n; i++) {
        if (a[1][i] <= a[1][i - 1]) check = false;
        if (a[i][1] <= a[i-1][1]) check = false;
    }
    if (check) cout << "Reduced";
    else cout << "Not Reduced";
}
signed main() {

    while (cin >> n) {
        solve();
        cout << "\n";
    }
}
