#include <bits/stdc++.h>
#define mod %
#define ll long long

using namespace std;
int Giang_Bae(int a, int b, int c, int R)
{
    if (a > b)
        swap(a, b);
    int l, r, res;
    l = c - R, r = c + R;
    if ((c >= a) && (c <= b))
    {
        l = l - a;
        if (l < 0)
            l = 0;
        r = b - r;
        if (r < 0)
            r = 0;
        return r + l;
    }
    if (c > b)
    {
        l = b - l + 1;
        if (l <= 0)
            l = 1;
        res = (b - a +1) - l;
        if (res < 0)
            res = 0;
        return res;
    }

    if (c < a)
    {
        r = r - a + 1;
        if (r <= 0)
            r = 1;
        res=(b - a +1) - r;
        if (res < 0)
            res = 0;
        return res;
    }
    return 0;
}
int main()
{
    int a, b, c, t, r;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> a >> b >> c >> r;
        cout << Giang_Bae(a, b, c, r) << endl;
    }
}