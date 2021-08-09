#include <bits/stdc++.h>
#define maxn 100001
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);

using namespace std;
int n, m;
vector<int> vertice[maxn];
int smlt[maxn];
bool fee[maxn];
void dfs(int u, int stt)
{
    fee[u] = true;
    smlt[u] = stt;
    for (auto v : vertice[u])
        if (fee[v] == false)
            dfs(v, stt);
}
int main()
{
    fastio;
    memset(fee, 0, sizeof(fee));
    int x, k, stt = 0, u, v;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        cin >> x >> k;
        if (k == 1)
        {
            vertice[x].push_back(i);
            vertice[i].push_back(x);
        }
    }
    for (int i = 1; i <= n; i++)
        if (fee[i] == false)
        {
            stt++;
            dfs(i, stt);
        }
    for (int i = 1; i <= m; i++)
    {
        cin >> u >> v;
        if (smlt[u] != smlt[v])
            cout << "YES";
        else
            cout << "NO";
        cout << endl;
    }
}