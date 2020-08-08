#include <bits/stdc++.h>
#define maxn 1001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
void solve()
{
    int n, x, u, v, step = 0;
    vector<int> vertice[maxn];
    cin >> n >> x;
    for (int i = 1; i < n; i++)
    {
        cin >> u >> v;
        vertice[u].push_back(v);
        vertice[v].push_back(u);
    }
    if (vertice[x].size() == 1)
    {
        cout << "Ashish \n";
        return;
    }
    step = n - vertice[x].size() + 1;
    step += vertice[x].size() - 1;
    if (step % 2 != 0)
        cout << "Ashish";
    else
        cout << "Ayush";
    cout << endl;
}
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        solve();
    }
}