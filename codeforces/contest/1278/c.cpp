#include <bits/stdc++.h>
#define ll long long
#define maxn 101

using namespace std;
int a[maxn * 2], l[maxn], r[maxn], trace_l[maxn], trace_r[100000];

int n;
void input()
{
    cin >> n;
    int temp;
    for (int i = 1; i <= n * 2; i++)
    {
        cin >> temp;
        if (temp == 1)
            a[i] = 1;
        else
            a[i] = -1;
    }
}
int Gb()
{
    l[0] = 0;
    r[n + 1] = 0;
    bool check[100000];
    memset(check, false, sizeof(check));
    for (int i = 1; i <= n; i++)
    {
        l[i] = l[i - 1] + a[i];
        // /cout << l[i] << " ";
    }
    for (int i = n * 2; i >= n; i--)
    {
        r[i] = r[i + 1] + a[i];
        trace_r[r[i]] = i;
        check[r[i]] = true;
    }
    int res = n * 2;
    for (int i = n; i >= 1; i--)
    {
        int t = trace_r[-l[i]];
        if (check[-l[i]] ==true)
            res = min(res, t - i - 1);
    }
    return res;
}
int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        input();
        cout << Gb() << endl;
    }
}