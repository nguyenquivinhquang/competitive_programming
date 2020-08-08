#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main()
{
    fastio;
    int testcase, n, temp, check;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        map<int, int> trace;
        int res = n + 1;
        for (int i = 1; i <= n; i++)
        {
            cin >> temp;
            if (trace[temp] != 0)
                res = min(res, i - trace[temp] + 1);
            trace[temp] = i;
        }
        if (res == n + 1)
            res = -1;
        cout << res << "\n";
    }
}