#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
vector<int> a, res;
int n;
int sum = 0, globalS = -1;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= 2  * n; i++) {
        int t; cin >> t;
        a.push_back(t);
        sum += t;
    }
    sort(a.begin(), a.end());
    do {
        vector<int> temp = a;
        for (auto v : a) temp.push_back(v);
        int curS = 0, localS = 0;
        for (int i = 0; i < n; i++) curS += temp[i];
        for (int i = n; i < 4 * n; i++) {
            curS -= temp[i- n];
            curS += temp[i];
            localS = max(localS, curS);
        }
        localS = sum - localS;
        if (localS > globalS) res = a, globalS = localS;
    } while (next_permutation(a.begin() + 1, a.end()));
    
    for  (auto v : res) cout <<  v << " ";
}
