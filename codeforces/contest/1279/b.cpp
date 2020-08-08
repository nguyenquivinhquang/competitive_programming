#include <bits/stdc++.h>
#define maxn 100001
#define mod %
using namespace     std;
int a[maxn];
int n;
int count(int s)
{
    int sum = 0;
    int i, max = 0, vt;
    max = a[1];
    vt = 1;
    for (i = 1; i <= n; i++)
    {
        sum = sum + a[i];
        if (a[i] > max)
        {
            max = a[i];
            vt = i;
        }
        if (sum > s)  return vt;
    }
    return 0;
}
int main()
{
    int t, s;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> s;
        for (int j = 1; j <= n; j++)
            cin >> a[j];
        cout << count(s) << endl;
    }
}