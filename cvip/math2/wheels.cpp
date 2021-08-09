#include <bits/stdc++.h>
#define maxn 1001
#define mod %
using namespace std;
struct wheels
{
    int x, y, gt, c, p, q; // c: chieu, 1 la thuan, 2 la nguoc
    double r;
    // p/q ;
};

wheels a[maxn];
int n = 0;
bool ways[maxn][maxn];
bool visited[maxn];
/* Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae Giang_Bae     */

bool giao(int x, int y)
{
    double distance = sqrt(pow(a[x].x - a[y].x, 2) + pow(a[x].y - a[y].y, 2));
    if (distance == a[x].r + a[y].r)
        return true;
    return false;
}
int gcd(int x, int y)
{
    if (x < y)
        swap(x, y);
    int r;
    while (y != 0)
    {
        r = x mod y, x = y, y = r;
    }
    return x;
}
void input()
{
    memset(ways, false, sizeof(ways));
    memset(visited, true, sizeof(visited));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y >> a[i].r;
        a[i].c=0,a[i].q=0,a[i].p=0;
    }
    a[1].c = 1;
    a[1].p = 1;
    a[1].q = 1;
}
int cal(int x, int y)
{
    int p, q, temp;
    p = a[x].r, q = a[y].r;
    temp = gcd(p, q);
    p = p / temp, q = q / temp;
    p = p * a[x].p, q = q * a[x].q;
    temp = gcd(p, q);
    p = p / temp, q = q / temp;
    a[y].p = p, a[y].q = q;
    a[y].c = a[x].c + 1;
    //cout<<p<<" "<<q;
}
void pre()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (giao(i, j) == true)
                ways[i][j] = true;
}
void dfs(int u)
{
    visited[u] = false;
    for (int v = 1; v <= n; v++)
        if ((visited[v] == true) && (ways[u][v] == true))
        {
            
            cal(u, v);
            dfs(v);
        }
    //visited[u] = true;
}
void output()
{
    for (int i = 1; i <= n; i++)
        if (a[i].q != 0)
        {
            if (a[i].q == 1)
                cout << a[i].p << " ";
            else
                cout << a[i].p << "/" << a[i].q << " ";
            if (a[i].c mod 2== 1)
                cout << "clockwise";
            else
                cout << "counterclockwise";

            cout << endl;
        }
        else
        {
            cout << "not moving" << endl;
        }
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        input();
        pre();
        dfs(1);
        output();
    }
}