#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 200009;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int father[N], permu[N], dis[N], w[N];
vector<int> child[N];
int n, root;
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        w[i] = -1;
        cin >> father[i];
        if (father[i] == i) root = i;
        else child[father[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++){
        cin >> permu[i];
        dis[permu[i]] = i;
    }
    w[root] = 0;
    bool check = true;
    for (int i = 1; i <= n; i++) {
        int u = permu[i];
        if (w[father[u]] == -1 || permu[1] != root) {
            check = false;
            break;
        }
        w[u] = i - dis[father[u]];
       
    }
    if (check) {
        for (int i = 1; i <= n; i++) cout << w[i] << " ";
    } else cout << -1;
    cout << "\n";
    for (int i = 1; i <= n; i++) child[i].clear();
}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int testcase = 1; 
    cin >> testcase;
    for (int t = 1; t <= testcase; t++) {
        solve();
    }
}
