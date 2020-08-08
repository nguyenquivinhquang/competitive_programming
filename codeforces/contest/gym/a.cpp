#include <bits/stdc++.h>
#define maxn 100
#define ll long long

using namespace std;
int main()

{
    int n, a[maxn];
    bool free[maxn];
    //memset(free, false, size_t(free));
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i], free[i] = true;
    for (int i = 1; i <= n; i++)
        if (free[i] == false)
        {
            cout << i;
            return 0;
        }
}