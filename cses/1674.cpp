#include <bits/stdc++.h>
#define maxn 200009 
using namespace std;
vector<int> tree[maxn];
int n, x, y, node[maxn];
vector<bool> fee(maxn, false);
void dfs(int i)
{
    fee[i] = true;
    node[i] = 1;
    for (auto c : tree[i])
    {
        dfs(c);
        node[i] += node[c];
    }
}
int main()
{
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        cin >> x;
        tree[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
        if (fee[i] == 0)
            dfs(i);
    for (int i = 1; i <= n; i++)
        cout << node[i] - 1 << " ";
}