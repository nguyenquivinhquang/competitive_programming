#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

const int N = 1000;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int n;
struct Vertice {
    int dest, cost, dpmin, dpmax;
};
vector<Vertice> vertice[N];
bool cmp(Vertice x, Vertice y) {
    return x.cost < y.cost;
}
void dfs1(int u, int PreU) {

}
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    int n; cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y, c; cin >> x >> y >> c;
        vertice[x].push_back({y, c, 0, 0});
        vertice[y].push_back({x, c, 0, 0});
    }
    for (int i = 1; i <= n; i++) sort(vertice[i].begin(), vertice[i].end(), cmp);
}
