#include <bits/stdc++.h>
#define maxn 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define inputfile freopen(input.txt, r, stdin)
#define outputfile freopen(out.txt, w, stdout)
using namespace std;
int main()
{
    int testcase;
    cin >> testcase;
    while (testcase--)
    {
        ll a, b, max_a, max_b;
        cin >> a >> b >> max_a >> max_b;
        if (max_a != 0 && max_b != 0 && a != 0 && b != 0)
        {
            ll res = min(a, b), pa = res, m = 0;
            a -= res, b -= res;
            res += res;
            ll t = max_a - 1;
            if (a == 0)
                t = max_b - 1;
            a = max(a, b);
            for (int i = 1; i <= pa; i++)
            {
                if (a - t >= 0)
                {
                    res += t;
                    a -= t;
                }
                else
                {
                    res += a;
                    a = 0;
                    break;
                }
            }
            if (a > 0)
                res += min(t + 1, a);
            cout << res;
        }
        else if (max_a == 0 && max_b == 0)
            cout << 0;
        else if ((max_a == 0 || a == 0) && max_b != 0)
            cout << min(b, max_b);
        else
            cout << min(a, max_a);
        cout << endl;
    }
}