#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const long long INF = 1000000000000000;
const long long M = 1000000007;
long n, m, s, t;
const int N = 2000002;
vector<pair<long, long> > g[N];
long long n_min[N];
int min_num[N], max_num[N];

int main() {
    // freopen("/mnt/Code/Competitive_Programming/cvip/create_Test/data/input/input44.txt", "r", stdin);
    long a, b, c;
    priority_queue<pair<long long, int> > q;
    cin >> n >> m;
    vector<long long> d(n + 1, INF);
    for (; m; --m) {
        // read graph
        cin >> a >> b;
        c = 1;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    d[1] = 0;
    n_min[1] = 1;
    q.push(make_pair(0, 1));
    while (!q.empty()) {
        int v = q.top().second;
        long long cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v]) continue;

        for (size_t j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first,
                len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                n_min[to] = n_min[v];
                min_num[to] = min_num[v] + 1;
                max_num[to] = max_num[v] + 1;
                q.push(make_pair(-d[to], to));
            } else if (d[v] + len == d[to]) {
                n_min[to] = (n_min[to] + n_min[v]) % M;
                min_num[to] = min(min_num[v] + 1, min_num[to]);
                max_num[to] = max(max_num[v] + 1, max_num[to]);
            }
        }
    }
    cout << n_min[n];
    return 0;
}