#include <bits/stdc++.h>
#define N 200005
//#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
using namespace std;
int n, q;
int succ[N][31];
int create_new(int x, int k)
{
    if (k == 0)
        return succ[x][0];
    if (succ[x][k] != -1)
        return succ[x][k];
    int t = succ[x][k - 1];
    if (t == -1)
        t = create_new(x, k - 1);
    int z = succ[t][k - 1];
    if (z == -1)
        z = create_new(t, k - 1);
    succ[x][k] = z;
    return succ[x][k];
}
int main()
{
    // cout << (1<<3);
    fastio;
    int x, k;
    memset(succ, -1, sizeof(succ));
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> succ[i][0];
    }
    for (int i = 1; i <= n; i++)
    {
        create_new(i, 30);
    }

    while (q--)
    {
        cin >> x >> k;
        int des = x;
        for (int i = 30; i >= 0; i--)
            if ((k & (1 << i)))
            {
                des = succ[des][i];
            }
        cout << des << endl;
    }
}