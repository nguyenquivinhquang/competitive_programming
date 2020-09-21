#include <bits/stdc++.h>
#define N 100
#define Quyen "Cute"
#define ll long long
#define pp pair<int,int>
#define fastio ios_base::sync_with_stdio(false),cin.tie(NULL);
#define reset(a,val) memset(a,val,sizeof(a));
#define modulo int(1e9+7)
#define endl '\n'
using namespace std;
vector<int> edge[N];
int n, m;
void dijkstra()
{
    int d[N];
    reset(d, 0);
   
}
int main()
{
    int x, y;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
}