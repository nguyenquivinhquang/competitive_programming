#include <bits/stdc++.h>
#define maxn 1001

using namespace std;
bool trace[maxn][maxn];
int a[maxn][maxn];
int n,m,room=0;
void dfs(int u, int v)
{
    if (trace[u][v]
}
int main()
{
    char temp;
    memset(trace,0, sizeof(trace));
    cin >> n >> m;
    for (int i=1; i<=n; i++)
        for (int j=1; j<=m; j++)
        {
            cin >> temp;
            if (temp=='.')
                a[i][j] =1; else a[i][j]=0;
        }
    
}