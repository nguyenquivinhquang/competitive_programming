#include <bits/stdc++.h>
#define maxn 101
#define mod %

using namespace std;

int main()
{

    int n, a[maxn], testcase, res = 0;

    cin >> testcase;
    while (testcase--)
    {
        res = 0;
        long long s = 0, p = 1;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i], s += a[i], p *= a[i];
            if (p == 0)
                p = 1, s++, res++;
            p = 1;
        }
        if (s == 0)
            res++;
        cout << res << endl;
    }
}