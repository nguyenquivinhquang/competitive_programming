#include <bits/stdc++.h>
#define maxn 300000
#define mod %

using namespace std;

int main()
{
    int testcase, a[maxn], n;
    cin >> testcase;
    while (testcase--)
    {
        cin >> n;
        for (int i = 1; i <= 2 * n; i++)
            cin >> a[i];
        sort(a + 1, a + 2 * n + 1);
        cout << a[n + 1] - a[n] << endl;
    }
}