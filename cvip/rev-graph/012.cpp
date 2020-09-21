#include <bits/stdc++.h>
#define N 105
#define ll long long
#define pp pair<int, int>
#define Quyen "cute"
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("r", "input.txt", stdin);
#define output_file freopen("w", "output.txt", stdout);
using namespace std;
vector<int> edge[N];
pp a[N], ss, ee;
int n;
bool fee[N];
void create_graph()
{
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            double x1 = a[i].first, y1 = a[i].second, x2 = a[j].first, y2 = a[j].second;
            if (abs(x1 - x2) + abs(y1 - y2) <= 1000)
            {
                edge[i].push_back(j);
                edge[j].push_back(i);
            }
        }
}
void dfs(int u)
{
    fee[u] = false;
    for (auto v : edge[u])
        if (fee[v] == true)
        {
            dfs(v);
        }
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        reset(fee, true);
        cin >> n;
        n += 2;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i].first >> a[i].second;
            if (edge[i].size())
                edge[i].clear();
        }
        create_graph();
        dfs(1);
        if (fee[n] == false)
            cout << "happy";
        else
            cout << "sad";
        cout << endl;
    }
}