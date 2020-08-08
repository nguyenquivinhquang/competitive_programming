#include <bits/stdc++.h>
#define ll long long
#define maxn 1000
using namespace std;

int main()
{
    int testcase, n, x, temp, t, res = 0;

    cin >> testcase;
    while (testcase--)
    {
        std::vector<bool> fee(maxn, false);
        std::vector<int> a;
        cin >> n >> x;
        t = 0, res = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            if (fee[temp] == false)
            {
                a.push_back(temp);
                fee[temp] = true;
                t++;

            }
        }
        n = t ;
        a.push_back(0);
        sort(a.begin(), a.end());
        for (int i = 1; i <= n; i++)
        {
            if (x >= a[i]) res = max(res, x + i);
            else if (x + i == a[i]) res = max(res, a[i]);
        }

        cout << res << endl;
    }
}