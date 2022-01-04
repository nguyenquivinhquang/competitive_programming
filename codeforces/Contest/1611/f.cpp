#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 200009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int l[N];
void solve() {
    vector<int> a;
    queue<int> q;
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int temp; cin >> temp;
        a.push_back(temp);
    } 
    int sum = m, maxL = 0;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        q.push(a[i]);
        while(q.size() && sum < 0) {
            sum -= q.front();
            q.pop();
        }
        l[i] = q.size();
        maxL = max(maxL, l[i]);
    }
    for (int i = 0; i < n; i++) 
        if (l[i] == maxL && maxL > 0){
            cout << i - maxL + 2<< " " << i + 1<< "\n";
            return;
        }
    cout << -1 << "\n";
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
