#include <bits/stdc++.h>
#define maxn 200009
using namespace std;

int a[maxn], b[maxn], c[maxn];

int main()
{
    int n, k;
    cin >> n >> k;
    int x = 0, y = 0, z = 0;
    for (int i = 1; i <= n; i++)
    {
        int d, e, f;
        cin >> d >> e >> f;
        if (e && f)
            a[++x] = d;
        if (e && !f)
            b[++y] = d;
        if (!e && f)
            c[++z] = d;
    }
    sort(b + 1, b + y + 1);
    sort(c + 1, c + z + 1);
    y = min(y, z);
    for (int i = 1; i <= y; i++)
    {
        a[++x] = b[i] + c[i];
    }
    if (x < k)
        cout << "-1" << endl;
    else
    {
        sort(a + 1, a + x + 1);
        int sum = 0;
        for (int i = 1; i <= k; i++)
            sum += a[i];
        cout << sum << endl;
    }
}
