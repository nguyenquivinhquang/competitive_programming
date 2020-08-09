#include <bits/stdc++.h>
#define ll long long
#define maxn 100001
using namespace std;
ll a[maxn], debt = 0, x[maxn], n, l, sum = 0;
int main()
{
    //freopen("D:\\c++\\cvip\\mashup1\\in.txt", "r", stdin);
    cin >> n >> l;
    for (int i = 1; i < n; i++)
        cin >> a[i];
    for (int i = 1; i <= l; i++)
    {
        x[i] = a[i];
        sum += a[i];
    }
    for (int i = l + 1; i < n; i++)
    {
        x[i] = min(a[i], sum);
        x[i - l] = x[i - l] - (debt + x[i]);
        debt = 0;
        if (x[i - l] >= 0)
            sum -= x[i - l];
        else
            debt -= x[i - l], x[i - l] = 0;
    }
    cout << sum;
}
/*
14 3
3 4 5 9 7 0 3 5 3 0 0 2 3

*/