#include <bits/stdc++.h>
#define maxn 1000001
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int n, up[maxn], down[maxn], h, m, height[maxn];
    memset(height, 0, sizeof(height));
    cin >> n >> h;
    for (int i = 1; i <= n; i++)
        if (i % 2 == 0)
            cin >> down[i / 2];
        else
            cin >> up[(i + 1) / 2];
    // n ~ up, m ~ down
    m = n / 2;
    n = (n + 1) / 2;
    sort(up + 1, up + 1 + n);
    sort(down + 1, down + 1 + m);
    int start = 0;
    up[0] = 0, down[0] = 0;
    for (int i = 1; i <= h; i++)
    {
        while (up[start] < i && start <= n)
        {
            start++;
            if (start > n)
                break;
        }
        height[i] = n - start + 1;
    }
    start = 0;
    for (int i = 1; i <= h; i++)
    {
        while (down[start] < i && start <= m)
        {
            start++;
            if (start > m)
                break;
        }
        height[h - i + 1] += m - start + 1;
    }

    int res = 1e9, sl = 1e9;
    for (int i = 1; i <= h; i++)
    {
        if (height[i] == res)
            sl++;
        else if (height[i] < res)
        {
            res = height[i];
            sl = 1;
        }
    }
    cout << res << " "<<sl;
}
 