#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
using namespace std;
int n, nChain[N];
vector<int> vertice[N];
int count_child(int u, int preu)
{
    int max_size = 1;
    for (auto v : vertice[u])
        if (v != preu)
        {
            max_size = max(count_child(v, u) + 1, max_size);
            
        }
    return max_size;
}
int main()
{
    int u, v;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
}