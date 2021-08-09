#include <bits/stdc++.h>
#define maxn n + 10
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n + 10];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int res = n;
    for (int i = 2; i <= n; i++)
        if (a[i] == a[i - 1])
            res--;
    cout << res << endl;
}