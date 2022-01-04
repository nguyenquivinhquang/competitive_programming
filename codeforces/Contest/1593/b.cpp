#include <bits/stdc++.h>
using namespace std;
#define int long long

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
    int n;
    vector<int> a;
    cin >> n;
    while (n > 0) {
        a.push_back(n % 10);
        n /= 10;
    }
    int res = a.size();
    reverse(a.begin(), a.end());
    for (int i = 0; i < a.size(); i++) {
        for (int j = i + 1; j < a.size(); j++) {
            int num = a[i] * 10 + a[j];
            int temp = 0;
            if (num % 25 != 0) continue;

            int total_remove = 0;
            for (int x = 0; x < i; x++) temp = temp * 10 + a[x];
            if (temp == 0 && num == 0) continue;
            for (int x = i + 1; x < j; x++) {
                total_remove++;
                
            }
            
            for (int x = j + 1; x < a.size(); x++) total_remove++;
            res = min(res, total_remove);
        }
    }
    cout << res << "\n";

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
