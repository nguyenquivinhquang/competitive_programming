#include <bits/stdc++.h>
#define maxn 200001
using namespace std;
struct node
{
    map<int, int> diff;
    vector<int> language, children;
};

int n, q, k, m, temp;
node a[maxn];
void dfs(int u, int preu)
{
    for (auto v : a[u].children)
        if (v != preu)
        {
            dfs(v, u);
            for (auto x : a[v].diff)
                a[u].diff[x.first] += x.second;
        }
    for (auto x : a[u].diff)
        a[u].language.push_back(x.second);
    sort(a[u].language.begin(), a[u].language.end());
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 2; i <= n; i++)
    {
        cin >> temp;
        a[i].children.push_back(temp);
        a[temp].children.push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> temp;
        a[i].diff[temp]++;
    }
    dfs(1, 0);
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> temp;
        auto pos = upper_bound(a[temp].language.begin(), a[temp].language.end(), k)-a[temp].language.begin();
        cout << pos << endl;
    }
}