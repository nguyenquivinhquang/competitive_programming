#include <bits/stdc++.h>
#define maxn 100001
using namespace std;

int main()
{
    int testcase, n;

    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        int Max = -1000000000, Min = 1000000000, m = -1, k, a[n + 10];
        for (int i = 1; i <= n; i++)
        {

            cin >> a[i];
        }
        for (int i = 1; i <= n; i++)
            if (a[i] == -1)
            {
                if (i + 1 <= n)
                    if (a[i + 1] != -1)
                    {
                        Max = max(Max, a[i + 1]);
                        Min = min(Min, a[i + 1]);
                    }
                if (i - 1 >= 1)
                    if (a[i - 1] != -1)
                    {
                        Max = max(Max, a[i - 1]);
                        Min = min(Min, a[i - 1]);
                    }
            }

        k = (Max + Min) / 2;
        if (a[1] == -1)
            a[1] = k;
        a[0] = a[1];
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == -1)
                a[i] = k;
            m = max(m, abs(a[i] - a[i - 1]));
        }
        cout << m << " " << k << endl;
    }
}