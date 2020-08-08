#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n = 1000000;
vector<bool> mark(n + 1, true);
vector<ll> snt(10000), sum(n + 1, 0);
int count_snt = 0;
void eratos()
{
    for (int i = 2; i <= n; i++)
    {
        if (mark[i])
        {
            for (int j = i * 2; j <= n; j += i)
            {
                mark[j] = false;
            }
        }
    }
    sum[1] == 0;
    for (int i = 2; i <= n; i++)
    if (mark[i]==true)
    {
        count_snt++;
        snt[count_snt]=i;
    }
}
int main()
{
    eratos();
    int t, x, y;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        ll t = 0;
        cin >> x >> y;
        if (mark[x] == true)
            t = x;
        t = sum[y] - sum[x] + t;
        cout << t << endl;
    }
}