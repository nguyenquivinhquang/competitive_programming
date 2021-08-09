// anti-cuongTrash
#include <bits/stdc++.h>
#define ll long long
#define maxn 200010
#define rn                       \
    for (int i = 2; i <= n; i++) \
    vertices.push(i)
#define quangcute n
using namespace std;
int n, m;
set<int> edge[maxn];
queue<int> vertices;
vector<int> trace, ans;

void Gb()
{
    trace.push_back(1);
    n--;
    int bd = 0, kt = 0, x, y, lim, dem = 1;
    while (quangcute != false)
    {
        if (bd > kt)
        {
            ans.push_back(dem), dem = 1;
            n--, kt++;
            trace.push_back(vertices.front());
            vertices.pop();
        }
        x = trace[bd];
        lim = n;
        while (lim--)
        {
            y = vertices.front();
            vertices.pop();
            if (edge[x].find(y) == edge[x].end())
            {
                kt++, n--, dem++;
                trace.push_back(y);
            }
            else
            {
                vertices.push(y);
            }
        }
        bd++;
    }
    ans.push_back(dem);
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].insert(y);
        edge[y].insert(x);
    }
    rn;
    Gb();
    sort(ans.begin(), ans.end());
    cout << ans.end() - ans.begin() <<endl;
    for (auto i : ans)
    {
        cout << i << " ";
    }
}
/*
5 7
1 2
2 3
3 4
1 5
2 5
3 5
4 5

*/