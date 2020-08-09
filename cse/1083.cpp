#include <bits/stdc++.h>
#define maxn 300009
using namespace std;

int main()
{
    int n, t;
    bool free[maxn];
    memset(free, false, sizeof(free));
    cin >> n;
    for (int i = 1; i < n; i++)
        cin >> t, free[t] = true;
    for (int i = 1; i <= n; i++)
        if (free[i] == false)
        {
            cout << i;
            return 0;
        }
}